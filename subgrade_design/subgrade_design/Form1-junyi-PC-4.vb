Imports System.Math
Imports subgrade_design.calculate_fun
Imports System.IO
Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ComboBox1.DropDownStyle = ComboBoxStyle.DropDownList
        ComboBox2.DropDownStyle = ComboBoxStyle.DropDownList
        ComboBox3.DropDownStyle = ComboBoxStyle.DropDownList
        TextBox1.TextAlign = HorizontalAlignment.Center
        TextBox2.TextAlign = HorizontalAlignment.Center
        TextBox3.TextAlign = HorizontalAlignment.Center
        TextBox4.Multiline = True
        TextBox4.ScrollBars = ScrollBars.Vertical
        TextBox4.TextAlign = HorizontalAlignment.Left
        TextBox4.ReadOnly = True
        TextBox4.WordWrap = True

        'Me.Chart1.ChartAreas(0).AxisX.ScaleBreakStyle =
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
        Dim q_g!, k30_u!, k30_s!, gamma_m!
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
        H = hh(v, c, p_out_max, q_g, gamma_m, p_load)
        H = Round(H * 100) / 100
#End Region

#Region "2.1-应力数据写入文件与绘制应力衰减图"
        Dim stw As StreamWriter
        stw = File.CreateText(Application.StartupPath & "\sigma.txt")

        Me.Chart1.Series("sigma").Points.Clear()
        For i = 0 To 200
            Dim sgm# = sigma(i * 0.05, p_out_max, p_load)
            Me.Chart1.Series("sigma").Points.AddXY(i * 0.05， sgm)
            stw.WriteLine(i * 0.05 & Space(2) & sgm)
        Next
        stw.Close()
#End Region

#Region "3-基床表层动强度与长期强度复核"
        '基床表层顶面动强度控制
        Dim sigma_djx!, sigma_dyx!， sigma_lcy!, sigma_lyx!
        '计算极限动应力用极限荷载动力系数phi_k1()
        sigma_djx = phi_k1(v) * sigma(c, p_out_max, p_load)
        sigma_dyx = sigma_d(k30_u)
        If sigma_djx >= sigma_dyx / safefactor Then
            MsgBox("表层动强度不足，请修改！"，， “请重新输入”)
            Exit Sub
        End If

        '计算常遇动应力用常遇荷载动力系数phi_k2()
        sigma_lcy = phi_k2(v) * sigma(c, p_out_max, p_load)
        sigma_lyx = sigma_l(k30_u)
        If sigma_lcy > sigma_lyx Then
            MsgBox("表层长期强度不足，请修改！"，， “请重新输入”)
            Exit Sub
        End If
#End Region

#Region "4-反算表层厚度"
        Dim u_d!, s_d!, s_yx#, s_sum#
        Dim flag_s As Boolean = False, flag_d As Boolean = False, flag_l As Boolean = False
        Dim u_d_control!, s_d_control!
        u_d = c
        s_yx = slimit(p_load) : sigma_dyx = sigma_d(k30_s) : sigma_lyx = sigma_l(k30_s)
#Region "4-1沉降反算表层厚度"
        '总沉降控制(二分法)
        Dim f = Function(z#)
                    Return s(c, H, (k30_u * z + k30_s * (H - c - z)) / H, p_out_max, p_load) - s_yx
                End Function
        Dim a#, b#, m#, eps#
        a = c : b = H : eps = 0.5
        Do
            m = (a + b) / 2
            Dim tx = f(a) * f(m)
            If tx < 0 Then
                b = m
            Else
                a = m
            End If
        Loop Until (b - a) / 2 < eps


        u_d = (a + b) / 2
        Do Until flag_s = True
            s_d = H - c - u_d
            If s_d < 0 Then
                Exit Sub
            End If
            s_sum = s(c, c + u_d, k30_u, p_out_max, p_load) _
                + s(c + u_d, H, k30_s, p_out_max, p_load)
            If s_sum >= s_yx Then
                u_d = u_d + 0.01
                Continue Do
            Else
                flag_s = True
            End If
        Loop
#End Region

#Region "4-2底层动强度反算表层厚度"
        '底层动强度控制,计算极限动应力用极限荷载动力系数phi_k1()
        Do Until flag_d = True
            s_d = H - c - u_d
            If s_d < 0 Then
                Exit Sub
            End If
            sigma_djx = phi_k1(v) * sigma(c + u_d, p_out_max, p_load)
            If sigma_djx >= sigma_dyx / 1.5 Then
                u_d = u_d + 0.01
                Continue Do
            Else
                flag_d = True
                u_d_control = u_d
            End If
        Loop
#End Region

#Region "4-3底层长期强度反算表层厚度"
        '底层长期强度控制,计算常遇动应力用常遇荷载动力系数phi_k2()
        Do Until flag_l = True
            s_d = H - c - u_d
            If s_d < 0 Then
                'Exit Sub
            End If
            sigma_lcy = phi_k2(v) * sigma(c + u_d, p_out_max, p_load)
            If sigma_lcy >= sigma_lyx Then
                u_d = u_d + 0.01
                Continue Do
            Else
                flag_l = True
                s_d_control = H - c - u_d
            End If
        Loop
#End Region
#End Region

#Region "5-输出结果（计算书）"


#End Region

    End Sub

    Private Sub TextBox4_GotFocus(sender As Object, e As EventArgs) Handles TextBox4.GotFocus
        Button1.Focus()
    End Sub
End Class
