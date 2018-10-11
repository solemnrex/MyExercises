Imports System.Math
Imports subgrade_design.calculate_fun
Imports System.IO
Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.MaximizeBox = False
        'Me.MinimizeBox = False
        Me.FormBorderStyle = Windows.Forms.FormBorderStyle.FixedSingle '设置窗口不能改变大小
        Me.Text = "重载铁路基床结构设计程序 V 0.9"
        NumericUpDown1.Maximum = 250
        NumericUpDown1.Minimum = 190
        NumericUpDown1.Value = 190
        NumericUpDown2.Maximum = 150
        NumericUpDown2.Minimum = 70
        NumericUpDown2.Value = 70
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        ComboBox1.DropDownStyle = ComboBoxStyle.DropDownList
        ComboBox2.DropDownStyle = ComboBoxStyle.DropDownList
        ComboBox3.DropDownStyle = ComboBoxStyle.DropDownList
        ComboBox1.Text = "30"
        ComboBox2.Text = "0.35"
        ComboBox3.Text = "100"
        TextBox1.TextAlign = HorizontalAlignment.Center
        TextBox2.TextAlign = HorizontalAlignment.Center
        TextBox3.TextAlign = HorizontalAlignment.Center
        TextBox4.Multiline = True
        TextBox4.ScrollBars = ScrollBars.Vertical
        TextBox4.TextAlign = HorizontalAlignment.Left
        TextBox4.ReadOnly = True
        TextBox4.WordWrap = True
        TextBox1.ReadOnly = True
        TextBox2.ReadOnly = True
        TextBox3.ReadOnly = True
        Label2.Text = "设计轴重："
        Label5.Text = "轨枕间距："

        Me.Chart1.Titles(0).Text = "" '"动应力影响深度的确定"
        Me.Chart1.Series(0).Name = "常遇动应力"
        Me.Chart1.Series(0).XAxisType = 0
        Me.Chart1.Series(0).YAxisType = 0
        Me.Chart1.Series(0).ChartType = DataVisualization.Charting.SeriesChartType.Line
        Me.Chart1.Series(0).Color = Color.Green
        Me.Chart1.Series(0).BorderWidth = 1.5

        Me.Chart1.Series.Add("极限动应力")
        Me.Chart1.Series(1).Color = Color.Purple
        Me.Chart1.Series(1).ChartType = DataVisualization.Charting.SeriesChartType.Line
        Me.Chart1.Series(1).Color = Color.Red
        Me.Chart1.Series(1).BorderWidth = 1.5

        Me.Chart1.Series.Add("0.2倍自重应力")
        Me.Chart1.Series(2).XAxisType = 0
        Me.Chart1.Series(2).YAxisType = 0
        Me.Chart1.Series(2).ChartType = DataVisualization.Charting.SeriesChartType.Line
        Me.Chart1.Series(2).Color = Color.Blue
        Me.Chart1.Series(2).BorderWidth = 1.5

        Me.Chart1.Legends(0).Enabled = True
        Me.Chart1.Legends(0).Docking = DataVisualization.Charting.Docking.Bottom

        Me.Chart1.ChartAreas(0).AxisY.Minimum = 0
        Me.Chart1.ChartAreas(0).AxisY.Maximum = 6
        Me.Chart1.ChartAreas(0).AxisY.Title = "深度 z/m"
        Me.Chart1.ChartAreas(0).AxisY.IsReversed = True
        Me.Chart1.ChartAreas(0).AxisY.MajorGrid.LineDashStyle = DataVisualization.Charting.ChartDashStyle.Dash
        Me.Chart1.ChartAreas(0).AxisY.MajorGrid.Interval = 0.5
        Me.Chart1.ChartAreas(0).AxisY.LabelStyle.Interval = 1
        Me.Chart1.ChartAreas(0).AxisY.ArrowStyle = DataVisualization.Charting.AxisArrowStyle.SharpTriangle
        Me.Chart1.ChartAreas(0).AxisY.MajorTickMark.Interval = 1

        Me.Chart1.ChartAreas(0).AxisX.Minimum = 0
        Me.Chart1.ChartAreas(0).AxisX.Maximum = 160
        Me.Chart1.ChartAreas(0).AxisX.Title = "应力/kPa"
        Me.Chart1.ChartAreas(0).AxisX.MajorGrid.LineDashStyle = DataVisualization.Charting.ChartDashStyle.Dash
        Me.Chart1.ChartAreas(0).AxisX.MajorGrid.Interval = 20
        Me.Chart1.ChartAreas(0).AxisX.LabelStyle.Interval = 20
        Me.Chart1.ChartAreas(0).AxisX.MajorTickMark.Interval = 20

        Me.Chart1.Series(0).Points.AddXY（160， 5)

        Me.Chart1.Series.Add("路基顶面")
        Me.Chart1.Series(3).Color = Color.Black
        Me.Chart1.Series(3).ChartType = DataVisualization.Charting.SeriesChartType.Line
        Me.Chart1.Series(3).BorderWidth = 2

        Me.Chart1.Series.Add("底层顶面")
        Me.Chart1.Series(4).Color = Color.BlueViolet
        Me.Chart1.Series(4).ChartType = DataVisualization.Charting.SeriesChartType.Line
        Me.Chart1.Series(4).BorderWidth = 2

        Me.Chart1.Series.Add("底层底面")
        Me.Chart1.Series(5).Color = Color.Purple
        Me.Chart1.Series(5).ChartType = DataVisualization.Charting.SeriesChartType.Line
        Me.Chart1.Series(5).BorderWidth = 2

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim percentage! = 0.9545
        Dim py(num_zjj) As Single    '数组py()用于储存各个车轴的相对偏移量
        Dim t(num_zjj) As Integer       '记录各轴作用范围内轨枕数目
        Dim temp_out(num_zjj)           '临时变量
        Dim n_c_R(num_zjj) As Integer   '记录各个轴对应的影响范围内轨枕数目
        py(0) = 0
        '图表初始化
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Chart1.Series(5).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
        '从界面读入数据—————————————————————
        d_crosstie = Val(TextBox1.Text) * 1000.0
        If d_crosstie <= 0 Then
            MsgBox(”轨枕中心距应大于零，请重新输入！“，， ”请重新输入“)
            Exit Sub
        End If
        Dim n% = Val(TextBox2.Text)
        If n <> Val(TextBox2.Text) Or n <= 0 Then
            MsgBox(”轨枕数为正整数，请重新输入！“，， ”请重新输入“)
            Exit Sub
        End If
        If Val(TextBox3.Text) <= 0 Or 1 <= Val(TextBox3.Text) Then
            MsgBox(”速度影响系数输入有误，请重新输入！“，， ”请重新输入“)
            Exit Sub
        End If
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
            temp_out(j) = cal(t(j), percentage, py(j)) '单轴分担比计算
            If j = 0 Then
                n_c_R(j) = t(j)
            Else
                n_c_R(j) = n_c_R(j - 1) - Ceiling(t(j - 1) / 2) _
                    + Int(py(j - 1) + 1800 / d_crosstie) + (-(py(j - 1) = 0)) _
                    + Floor(t(j) / 2)
            End If
        Next j

        '四轴分担比叠加
        ReDim p_out(n_c_R(n_c_R.Length - 1) - 1)
        Dim n_c_L(n_c_R.Length - 1) As Integer
        For j = 0 To num_zjj
            n_c_L(j) = n_c_R(j) - t(j) + 1
            For k = n_c_L(j) To n_c_R(j)
                p_out(k - 1) = p_out(k - 1) + temp_out(j)(k - n_c_L(j))
            Next k
        Next j

        '求最大分担比，记录
        Dim pmax# = 0, py0_pmax# = 0
        For i = Int(p_out.Length / 2) To 0 Step -1
            Dim num = p_out(i)
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
            bed_c = 0.35 : q_g = 17.7 : gamma_m = 20.5
        ElseIf ComboBox2.Text = "0.5" Then
            bed_c = 0.5 : q_g = 20.726 : gamma_m = 20.5
        End If
        p_load = Val(ComboBox1.Text)
        k30_u = NumericUpDown1.Value
        k30_s = NumericUpDown2.Value
        '表层k30值检查
        If k30_u < 190 Or 1000 < k30_u Then
            MsgBox("表层 K30 值输入有误，请检查。", , "请重新输入")
            Exit Sub
        End If
        '底层K30值检查
        If k30_u < 70 Or 1000 < k30_u Then
            MsgBox("表层 K30 值输入有误，请检查。", , "请重新输入")
            Exit Sub
        End If
        '表层K30与底层K30逻辑检查
        If k30_u < k30_s Then
            MsgBox("表层K30值小于底层K30值，请检查。", , "请重新输入")
            Exit Sub
        End If
        'H为动荷载显著影响范围，u_d为基床表层厚度,s_d为基床底层厚度
        Dim H#
        H = hh(v, bed_c, p_out_max, q_g, gamma_m, p_load)
#End Region

#Region "2.1-应力数据写入文件与绘制应力衰减图"
        Dim stw As StreamWriter
        stw = File.CreateText(Application.StartupPath & "\sigma_djx.dat")

        Me.Chart1.Series("常遇动应力").Points.Clear()
        Me.Chart1.Series("0.2倍自重应力").Points.Clear()
        For i = 1 To 200  '绘图深度为0.05＊200=10m
            Dim sgm# = sigma(i * 0.05, p_out_max, p_load) * phi_k2(v)
            Dim sgmjx# = sigma(i * 0.05, p_out_max, p_load) * phi_k1(v)
            Me.Chart1.Series("常遇动应力").Points.AddXY（sgm， i * 0.05)
            Me.Chart1.Series("极限动应力").Points.AddXY（sgmjx， i * 0.05)
            If i * 0.05 > bed_c Then
                Me.Chart1.Series("0.2倍自重应力").Points.AddXY(0.2 * q(i * 0.05, q_g, gamma_m, bed_c)， i * 0.05)
            End If
            stw.WriteLine(i * 0.05 & Space(2) & sgm)
        Next
        stw.Close()
#End Region

#Region "3-基床表层动强度与长期强度复核"
        '基床表层顶面动强度控制
        Dim biaoceng_sigma_djx#, biaoceng_sigma_dyx#， biaoceng_sigma_lcy#, biaoceng_sigma_lyx#
        '计算极限动应力用极限荷载动力系数phi_k1()
        biaoceng_sigma_djx = phi_k1(v) * sigma(bed_c, p_out_max, p_load)
        biaoceng_sigma_dyx = sigma_d(k30_u)
        If biaoceng_sigma_djx >= biaoceng_sigma_dyx / safefactor Then
            MsgBox("表层动强度不足，请修改参数！"，， "请重新输入")
            Exit Sub
        End If

        '计算常遇动应力用常遇荷载动力系数phi_k2()
        biaoceng_sigma_lcy = phi_k2(v) * sigma(bed_c, p_out_max, p_load)
        biaoceng_sigma_lyx = sigma_l(k30_u)
        If biaoceng_sigma_lcy > biaoceng_sigma_lyx Then
            MsgBox("表层长期强度不足，请修改参数！"，， "请重新输入")
            Exit Sub
        End If
#End Region

#Region "4-由底层强度及基床沉降反算表层厚度"
        Dim u_d#, s_yx!
        Dim flag_s As Boolean = False, flag_d As Boolean = False, flag_l As Boolean = False
        Dim diceng_sigma_dyx#, diceng_sigma_lyx#
        Dim u_d_s_s#, u_d_s_d#, u_d_s_l#
        s_yx = slimit(p_load)
        diceng_sigma_dyx = sigma_d(k30_s)
        diceng_sigma_lyx = sigma_l(k30_s)
#Region "4-1总沉降反算表层厚度"
        '应当先对两种极端情况进行考察，有解之后
        '采用割线法求解，esp为求解精度，n为最大迭代次数
        '定义局部函数，其值为当表层为hk时，基床总沉降与允许沉降的差值，小于零时满足变形条件
        Dim f = Function(hk#) As Double
                    Return s(bed_c, bed_c + hk, k30_u, p_out_max, p_load) +
                     s(bed_c + hk, H, k30_s, p_out_max, p_load) - s_yx
                End Function
        '注意到f(0)>f(H-bed_c)的数量关系
        If f(0) <= 0 Then
            u_d_s_s = 0
        ElseIf f(H - bed_c) >= 0 Then
            Debug.Print(f(0))
            Debug.Print(f(H - bed_c))
            MsgBox("总沉降超限，请修改参数！"，， "请重新输入")
            Exit Sub
        ElseIf f(H - bed_c) < 0 Then

            '割线法
            Dim Secant1 = Function()
                              Dim x0#, x1#, eps#, max_itera%
                              max_itera = 100
                              eps = 0.0000001
                              '初始化
                              x0 = 0
                              x1 = 0.001
                              Dim y0 = f(x0), y1#
                              Dim diff#, x2#
                              Do
                                  y1 = f(x1)
                                  diff = (y1 - y0) / (x1 - x0)
                                  x2 = x1 - y1 / diff
                                  x0 = x1
                                  y0 = y1
                                  x1 = x2
                                  max_itera = max_itera - 1
                              Loop While (Abs(x1 - x0) > eps And max_itera)
                              Return x2
                          End Function
            u_d_s_s = Secant1()
        End If

#End Region

#Region "4-2底层动强度反算表层厚度"
        '底层动强度控制,计算极限动应力用极限荷载动力系数phi_k1()
        Dim ff = Function(z#) '小于零时满足强度条件
                     Dim diceng_sigma_djx = phi_k1(v) * sigma(bed_c + z, p_out_max, p_load)
                     Return diceng_sigma_djx - diceng_sigma_dyx / safefactor
                 End Function
        Debug.Print(ff(0))
        Debug.Print(ff(H - bed_c))
        If ff(0) <= 0 Then
            u_d_s_d = 0
        ElseIf ff(H - bed_c) >= 0 Then
            MsgBox("底层动强度不足，请修改参数！"，， "请重新输入")
            Exit Sub
        ElseIf ff(H - bed_c) < 0 Then

            '割线法
            Dim Secant2 = Function()
                              Dim x0#, x1#, eps#, max_itera%
                              max_itera = 100
                              eps = 0.0000001
                              '初始化
                              x0 = 0
                              x1 = 0.001
                              Dim y0 = ff(x0), y1#
                              Dim diff#, x2#
                              Do
                                  y1 = ff(x1)
                                  diff = (y1 - y0) / (x1 - x0)
                                  x2 = x1 - y1 / diff
                                  x0 = x1
                                  y0 = y1
                                  x1 = x2
                                  max_itera = max_itera - 1
                              Loop While (Abs(x1 - x0) > eps And max_itera)
                              Return x2
                          End Function
            u_d_s_d = Secant2()
        End If
#End Region

#Region "4-3底层长期强度反算表层厚度"
        '底层长期强度控制,计算常遇动应力用常遇荷载动力系数phi_k2()
        Dim fff = Function(z#) '小于零时满足长期条件
                      Dim diceng_sigma_lcy = phi_k2(v) * sigma(bed_c + z, p_out_max, p_load)
                      Return diceng_sigma_lcy - diceng_sigma_lyx
                  End Function
        If fff(0) <= 0 Then
            u_d_s_l = 0
        ElseIf fff(H - bed_c) >= 0 Then
            MsgBox("底层长期强度不足，请修改参数！"，， "请重新输入")
            Exit Sub
        ElseIf fff(H - bed_c) < 0 Then

            '割线法
            Dim Secant3 = Function()
                              Dim x0#, x1#, eps#, max_itera%
                              max_itera = 100
                              eps = 0.0000001
                              '初始化
                              x0 = 0
                              x1 = 0.001
                              Dim y0 = fff(x0), y1#
                              Dim diff#, x2#
                              Do
                                  y1 = fff(x1)
                                  diff = (y1 - y0) / (x1 - x0)
                                  x2 = x1 - y1 / diff
                                  x0 = x1
                                  y0 = y1
                                  x1 = x2
                                  max_itera = max_itera - 1
                              Loop While (Abs(x1 - x0) > eps And max_itera)
                              Return x2
                          End Function
            u_d_s_l = Secant3()
        End If
        u_d = Max(u_d_s_s, Max(u_d_s_d, u_d_s_l))
#End Region

#End Region

#Region "5-输出结果（计算书）"
        Dim hd#
        hd = bed_c + Max(Max(u_d_s_s, u_d_s_d), u_d_s_l)
        Me.Chart1.Series("路基顶面").Points.AddXY(0, bed_c)
        Me.Chart1.Series("路基顶面").Points.AddXY(160, bed_c)
        Me.Chart1.Series("底层顶面").Points.AddXY(0, hd)
        Me.Chart1.Series("底层顶面").Points.AddXY(160, hd)
        Me.Chart1.Series("底层底面").Points.AddXY(0, H)
        Me.Chart1.Series("底层底面").Points.AddXY(160, H)
        With TextBox4
            .Text = ""
            .TextAlign = HorizontalAlignment.Left
            .Text = "计算说明书" & vbCrLf &
                            "-------------------------------------------------------" & vbCrLf &
                            "设计轴重：  " & ComboBox1.Text & "t" & Space(4) & "速度：  " & ComboBox3.Text & "km/h" & Space(4) & "轨枕间距：  " & TextBox1.Text & "m" & vbCrLf &
                            "单轴作用区域内轨枕数目：    " & TextBox2.Text & "个" & vbCrLf &
                            "安全系数：    " & Format(safefactor, "#0.00") & vbCrLf &
                            "计算采用4Z1800标准荷载模式进行计算。" & vbCrLf & vbCrLf &
                            "1.确实动应力影响范围" & vbCrLf &
                            "按照常遇动附加应力与自重应力之比为0.2确定动应力影响深度H。" & vbCrLf &
                            "计算可得：" & vbCrLf &
                            "           H = " & Ceiling(H * 100) / 100 & "m" & vbCrLf &
                            "   常遇动应力 = " & Format(sigma(H, p_out_max, p_load) * phi_k2(v), "#0.00") & "kPa" &
                            "   自重应力 = " & Format(q(H, q_g, gamma_m, bed_c), "#0.00") & "kPa" & vbCrLf &
                            " 0.2倍自重应力 = " & Format(0.2 * q(H, q_g, gamma_m, bed_c), "#0.00") & "kPa" & vbCrLf &
                            "2.表层强度复核" & vbCrLf &
                            "表层极限动应力" & Space(5) & "<" & Space(5) & "表层允许动应力" & vbCrLf &
                              Space(10) & Format(biaoceng_sigma_djx, "#0.00") & "kPa" & Space(10) & Format(biaoceng_sigma_dyx, "#0.00") & "kPa" & vbCrLf &
                            "表层常遇动应力" & Space(5) & "<" & Space(5) & "表层允许长期动应力" & vbCrLf &
                              Space(10) & Format(biaoceng_sigma_lcy, "#0.00") & "kPa" & Space(10) & Format(biaoceng_sigma_lyx, "#0.00") & "kPa" & vbCrLf &
                            "表层计算通过。" & vbCrLf &
                            "3.反算表层厚度" & vbCrLf &
                            "由总变形反算表层厚度：" & vbCrLf &
                            "     h1 = " & Format(u_d_s_s, "#0.00") & "  m" & vbCrLf & "    此时,基床总沉降为" & Format(f(u_d_s_s) + s_yx, "#0.00") & "mm," &
                            " 变形限值为" & Format(s_yx, "#0.00") & "mm。" & vbCrLf &
                            IIf(u_d_s_s = 0, "    变形条件不受控制。", "") & vbCrLf &
                            "由底层动强度反算表层厚度：" & vbCrLf &
                            "     h2 = " & Format(u_d_s_d, "#0.00") & "  m" & vbCrLf & "    此时，底层表面极限动应力为" & Format(ff(u_d_s_d) + diceng_sigma_dyx / safefactor, "#0.00") & "kPa，" &
                            " 允许动应力除以安全系数为" & Format(diceng_sigma_dyx / safefactor, "#0.00") & "kPa。" & vbCrLf &
                            "由底层长期强度反算表层厚度：" & vbCrLf &
                            "     h3 = " & Format(u_d_s_l, "#0.00") & "  m" & vbCrLf & "    此时，底层表面常遇动应力为" & Format(fff(u_d_s_l) + diceng_sigma_lyx, "#0.00") & "kPa，" &
                            " 长期稳定荷载阈值为" & Format(diceng_sigma_lyx, "#0.00") & "kPa。" & vbCrLf & vbCrLf &
                            "综上，取最大值得，h = " & Format(Max(Max(u_d_s_s, u_d_s_d), u_d_s_l), "#0.00") & "  m" & vbCrLf & vbCrLf &
                            "基床结构总厚度为：" & Format(H - bed_c, "#0.00") & "  m" & vbCrLf &
                            "结构形式如下：" & vbCrLf &
                            "-----------------------------------------------------" & vbCrLf &
                            Space(10) & bed_c & "  m 道床" & vbCrLf &
                            "-----------------------------------------------------" & vbCrLf &
                            Space(10) & Format(Max(Max(u_d_s_s, u_d_s_d), u_d_s_l), "#0.00") & "  m 基床表层" & Space(5) & "K30值 " & k30_u & "MPa/m" & vbCrLf &
                            "-----------------------------------------------------" & vbCrLf &
                            Space(10) & Format(H - bed_c - Max(Max(u_d_s_s, u_d_s_d), u_d_s_l), "#0.00") & "  m 基床底层" & Space(5) & "K30值 " & k30_s & "MPa/m" & vbCrLf &
                            "-----------------------------------------------------" & vbCrLf &
                            ""
        End With

#End Region
                    Button2.Enabled = True
                    结果存盘ToolStripMenuItem.Enabled = True
    End Sub

    Private Sub TextBox4_GotFocus(sender As Object, e As EventArgs) Handles TextBox4.GotFocus
        Button1.Focus()
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub TextBox1_TextChanged(sender As Object, e As EventArgs) Handles TextBox1.TextChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub TextBox2_TextChanged(sender As Object, e As EventArgs) Handles TextBox2.TextChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub ComboBox2_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox2.SelectedIndexChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub ComboBox3_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox3.SelectedIndexChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub TextBox3_TextChanged(sender As Object, e As EventArgs) Handles TextBox3.TextChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub NumericUpDown1_ValueChanged(sender As Object, e As EventArgs) Handles NumericUpDown1.ValueChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub NumericUpDown2_ValueChanged(sender As Object, e As EventArgs) Handles NumericUpDown2.ValueChanged
        Button2.Enabled = False
        结果存盘ToolStripMenuItem.Enabled = False
        TextBox4.Text = ""
        Debug.WriteLine(Chart1)
        Try
            Chart1.Series(0).Points.Clear()
            Chart1.Series(1).Points.Clear()
            Chart1.Series(2).Points.Clear()
            Chart1.Series(3).Points.Clear()
            Chart1.Series(4).Points.Clear()
            Me.Chart1.Series(0).Points.AddXY（160， 5)
        Catch
        End Try
    End Sub

    Private Sub 结果存盘ToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles 结果存盘ToolStripMenuItem.Click
        Button2_Click(sender, e)
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim saveFileDialog1 As New SaveFileDialog()
        saveFileDialog1.Filter = "TextFiles|*.txt|AllFiles|*.*"
        saveFileDialog1.Title = "保存计算书"
        saveFileDialog1.FilterIndex = 0
        If saveFileDialog1.ShowDialog = DialogResult.OK Then
            Dim FS As FileStream = saveFileDialog1.OpenFile
            Dim SW As New StreamWriter(FS)
            SW.Write(TextBox4.Text)
            SW.Close()
            FS.Close()
        End If
    End Sub
    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        End
    End Sub

    Private Sub 关于ToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles 关于ToolStripMenuItem.Click
        MsgBox("重载铁路基床结构设计程序 V 1.00", vbOKCancel, "关于本软件")
    End Sub

    Private Sub PictureBox1_Click(sender As Object, e As EventArgs) Handles PictureBox1.Click

    End Sub

    Private Sub MenuStrip1_ItemClicked(sender As Object, e As ToolStripItemClickedEventArgs) Handles MenuStrip1.ItemClicked

    End Sub
End Class
