Imports System.Math
Imports subgrade_design.calculate_fun
Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim percentage! = 0.9544
        Dim py(num_zjj) As Single    '数组py()用于储存各个车轴的相对偏移量
        Dim t(num_zjj) As Integer       '记录各轴作用范围内轨枕数目
        Dim temp_out(num_zjj)           '临时变量
        Dim n_c_R(num_zjj) As Integer   '记录各个轴对应的影响范围内轨枕数目
        py(0) = 0

        '从界面读入数据—————————————————————
        Dim n% = Val(TextBox2.Text)
        d_crosstie = Val(TextBox1.Text) * 1000.0
        p_load = Val(ComboBox1.Text)
        v = Val(ComboBox3.Text)


#Region "1-分担比计算"
        '开始计算————————————————————————
        For j = 1 To num_zjj
            py(j) = py(j - 1) + 1800 / d_crosstie -
                Int(py(j - 1) + 1800 / d_crosstie)
        Next j

        For j = 0 To num_zjj
            If py(j) = 0 Then t(j) = n Else t(j) = n + 1
            temp_out(j) = cal(t(j), percentage, py(j))
            If j = 0 Then
                n_c_R(j) = t(j)
            Else
                n_c_R(j) = n_c_R(j - 1) - Ceiling(t(j - 1) / 2) _
                    + Int(py(j - 1) + 1800 / d_crosstie) + (-(py(j - 1) = 0)) _
                    + Floor(t(j) / 2)
            End If
        Next j

        '叠加
        ReDim p_out(n_c_R(n_c_R.Length - 1) - 1)
        Dim n_c_L(n_c_R.Length - 1) As Integer
        For j = 0 To num_zjj
            n_c_L(j) = n_c_R(j) - t(j) + 1
            For k = n_c_L(j) To n_c_R(j)
                p_out(k - 1) = p_out(k - 1) + temp_out(j)(k - n_c_L(j))
            Next k
        Next j

        '求最大分担比，记录
        Dim pmax! = 0, py0_pmax! = 0
        For Each num In p_out
            If num > pmax Then
                pmax = num
                py0_pmax = py(0) * d_crosstie
                ReDim p_out_max(p_out.Length - 1)
                For j = 0 To p_out.Length - 1
                    p_out_max(j) = p_out(j)
                Next
            End If
        Next
#End Region

#Region "2-计算应力函数与动力影响深度"
        Dim c!, q_g!, k30_u!, k30_s!, gamma_m!
        If ComboBox2.Text = "0.35" Then
            c = 0.35 : q_g = 17.7 : gamma_m! = 20.5
        ElseIf ComboBox2.Text = "0.5" Then
            c = 0.5 : q_g = 20.726 : gamma_m! = 20.5
        End If
        p_load = Val(ComboBox1.Text)
        k30_u = NumericUpDown1.Value
        k30_s = NumericUpDown2.Value

        'H为动荷载显著影响范围，u_d为基床表层厚度,s_d为基床底层厚度
        Dim H#
        H = calculate_fun.H(v, c, p_out_max, q_g, gamma_m, p_load)
#End Region

        For i = 0 To 200
            Me.Chart1.Series("sigma").Points.AddXY(sigma(i * 0.05, p_out_max, p_load), i * 0.05)
        Next

#Region "3-基床表层动强度反算表层厚度"
        '基床表层动强度控制
        Dim sigma1!, sigma_d!
        sigma1 = phi_k1(v) * sigma(c, p_out_max, p_load)
        sigma_d = calculate_fun.sigma_d(k30_u)
        If sigma1 >= sigma_d / 1.5 Then
            MsgBox("表层强度不够")
            Exit Sub
        End If



        ''逐步增大u_d，求k30_u、k30_s对应的最小u_d
        'Dim flag%
        'Dim s!, slimit!
        'Dim sigma1#, sigma2#, sigma_d#, sigma_l#
        ''基床表层动强度控制
        'sigma1 = calculate_fun.phi_k1(v) * calculate_fun.sigma(c, p_out_max, p_load)
        'sigma_d = calculate_fun.sigma_d(k30_u)
        'If sigma1 >= sigma_d / 1.5 Then
        '    MsgBox("")
        '    Exit Sub
        'End If
        ''基床表层长期强度控制
        'sigma2 = calculate_fun.phi_k2(v) * calculate_fun.sigma(c, p_out_max, p_load)
        'sigma_l = calculate_fun.sigma_l(k30_u)
        'If sigma2 >= sigma_l Then
        '    MsgBox("")
        '    Exit Sub
        'End If
        'Do Until flag <> 0
        '    s_d = H - u_d
        '    '总沉降控制
        '    slimit =slimit(p_load)
        '    's = calculate_fun.s(c, c + u_d, k30_u, p_out_max, p) + calculate_fun.s(c + u_d, H, k30_s, p_out_max, p)
        '    s = calculate_fun.s(c, H, k30_u * u_d + k30_s * s_d / H, p_out_max, p_load)
        '    If s >= slimit Then u_d = u_d + 0.01 ： Continue Do
        '    '底层动强度控制
        '    sigma1 = phi_k1(v) * sigma(c + u_d(), p_out_max, p_load)
        '    sigma_d = calculate_fun.sigma_d(k30_s)
        '    If sigma1 >= sigma_d / 1.5 Then u_d = u_d + 0.01 ： Continue Do

        '    '底层长期强度控制
        '    sigma2 = calculate_fun.phi_k2(v) * calculate_fun.sigma(c + u_d, p_out_max, p_load)
        '    sigma_l = calculate_fun.sigma_l(k30_s)
        '    If sigma2 >= sigma_l Then u_d = u_d + 0.01 ： Continue Do
        '    flag = 1
        'Loop
#End Region
    End Sub

End Class
