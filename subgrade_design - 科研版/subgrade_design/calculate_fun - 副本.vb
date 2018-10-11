Imports System.Math
Class calculate_fun

    '循环变形s(mm)
    Shared Function s#(s_p!, e_p!, Ex!, p_out_max() As Double, p!)
        '轴重p的输入单位为t,Ex单位为MPa
        Dim k1#, k2#, k3#, k4#, x#, y#, n%, d#
        x = s_p
        n = 5
        d = (e_p - s_p) / n
        '应力要乘常遇荷载动力系数 phi_k2()
        For i = 0 To n
            k1 = sigma(x, p_out_max, p)
            k2 = sigma(x + d / 2, p_out_max, p)
            k3 = sigma(x + d / 2, p_out_max, p)
            k4 = sigma(x, p_out_max, p)
            y = y + d / 6 * (k1 + 2 * k2 + 2 * k3 + k4) * phi_k2(v)
            x = x + d
        Next i
        Return y / Ex
    End Function

    '基床循环变形限值slimit(mm),p(t)
    Shared Function slimit!(p_load!)
        Return 0.05 * p_load 'pload单位为t
    End Function

    '长期稳定荷载阈值sigma_l(kPa)
    Shared Function sigma_l!(k30!)
        Return 0.23 * sigma_0(k30)
    End Function

    '动允许强度sigma_d(kPa)
    Shared Function sigma_d!(k30!)
        Return 0.45 * sigma_0(k30)
    End Function

    '静允许强度sigma_0(kPa)
    Shared Function sigma_0!(k30!)
        Return 2.4 * k30 + 15
    End Function

    '动荷载显著影响深度H
    Shared Function hh!(v!, c!, p_out_max() As Double, q_g!, gamma_m!, p!) '轴重p的输入单位为t
        '二分法
        Dim f = Function(z#)
                    Return phi_k2(v) * sigma(z, p_out_max, p) - 0.2 * q(z, q_g, gamma_m, c)
                End Function
        Dim a#, b#, m#, eps#
        a = c : b = 10 : eps = 0.001
        Do
            m = (a + b) / 2
            If f(a) * f(m) < 0 Then
                b = m
            Else
                a = m
            End If
        Loop Until (b - a) / 2 < eps
        Return (a + b) / 2
    End Function

    '自重应力函数q
    Shared Function q!(z!, q_g!, gama_m!, c!)
        Return q_g + gama_m * (z - c)
    End Function

    '极限极限荷载动力系数phi_k1
    Shared Function phi_k1!(v!)
        'alpha取4e-3
        Return 1 + v * 0.004
    End Function

    '常遇荷载动力系数phi_k2
    Shared Function phi_k2!(v!)
        'alpha取4e-3
        Return 1 + v * 0.004 / 3
    End Function
    '附加应力分布函数
    Shared Function sigma#(z!, p_out_max#()， p!)
        '轴重p的输入单位为t，输出应力单位为 kPa
        p = p * 10 '重力加速度 g 近似取10 m/s^2
        Dim t As Double, n_max As Short, result As Double, temp As Double
        '找到最大荷载分担比处的轨枕编号
        For i = 0 To p_out_max.Length - 1
            If t < p_out_max(i) Then
                t = p_out_max(i)
                n_max = i
            End If
        Next i

        For i = 0 To 1
            For j = 0 To p_out_max.Length - 1
                If j = n_max And i = 0 Then
                    temp = Boussinesq2(p_out_max(j) * p / 2 / (1090 * 320 / 1000000.0), 545 / 160, z / 0.16, z) * 4
                Else
                    temp = Boussinesq1(p_out_max(j) * p / 2, Sqrt((i * 1.51) ^ 2 + ((j - n_max) * 0.6) ^ 2 + z ^ 2), z)
                End If
                result = result + temp
            Next j
        Next i
        Return result
    End Function

    '集中力作用下boussinesq应力分布函数
    Shared Function Boussinesq1(p0#, r#, z#)
        Return 1.5 * p0 * z ^ 3 / PI / r ^ 5
    End Function

    '均布矩形荷载作用下boussinesq应力分布函数
    Shared Function Boussinesq2(p#, m#, n#, z#)
        Return p / 2 / PI * (Atan(m / n / Sqrt(1 + m * m + n * n)) +
            m * n / Sqrt(1 + m * m + n * n) * (1 / (m * m + n * n) + 1 / (1 + n * n)))
    End Function

    '荷载分担比例计算函数cal
    Shared Function cal(n%, p!, p0!) As Double()

        Dim h#, d#
        Dim xl(n - 1) As Double, xr(n - 1) As Double
        Dim p_out(n - 1) As Double
        Dim sum#
        h = norminv(1 - (1 - p) / 2) * IIf(n Mod 2 = 1, 1, n / (n - 1))
        d = 2 * h / n
        If n Mod 2 = 0 Then p0 = p0 - 0.5
        For i = 0 To n - 1
            xl(i) = (i - n / 2 - p0) * d
            xr(i) = (i + 1 - n / 2 - p0) * d
            p_out(i) = normcdf(xr(i)) - normcdf(xl(i))
            sum = sum + p_out(i)
        Next i
        For i = 0 To n - 1
            p_out(i) = p_out(i) / sum
        Next i
        Return p_out
    End Function

    '正态分布分位函数
    Shared Function norminv#(p#)
        Return Sqrt(2) * erfinv(2 * p - 1)
    End Function

    '逆误差函数
    Shared Function erfinv#(x#)
        Dim p#, w#
        w = -Log((1.0 - x) * (1.0 + x))
        If w < 5.0 Then
            w = w - 2.5
            p = 0.0000000281022636
            p = 0.000000343273939 + p * w
            p = -0.0000035233877 + p * w
            p = -0.00000439150654 + p * w
            p = 0.00021858087 + p * w
            p = -0.00125372503 + p * w
            p = -0.00417768164 + p * w
            p = 0.246640727 + p * w
            p = 1.50140941 + p * w

        Else
            w = Sqrt(w) - 3.0
            p = -0.000200214257
            p = 0.000100950558 + p * w
            p = 0.00134934322 + p * w
            p = -0.00367342844 + p * w
            p = 0.00573950773 + p * w
            p = -0.0076224613 + p * w
            p = 0.00943887047 + p * w
            p = 1.00167406 + p * w
            p = 2.83297682 + p * w
        End If
        Return p * x
    End Function

    '正态分布的累积分布函数
    Shared Function normcdf#(x#)
        Return 0.5 * (1 + erf(x / Sqrt(2)))
    End Function

    '误差函数
    Shared Function erf#(x#)
        '数值近似，定义域内精度1.2e-7
        Dim t#, tao#
        t = 1 / (1 + 0.5 * Abs(x))
        tao = t * Exp(-x ^ 2 - 1.26551223 + 1.00002368 * t + 0.37409196 * t ^ 2 _
                      + 0.09678418 * t ^ 3 - 0.18628806 * t ^ 4 + 0.27886807 * t ^ 5 _
                      - 1.13520398 * t ^ 6 + 1.48851587 * t ^ 7 _
                      - 0.82215223 * t ^ 8 + 0.17087277 * t ^ 9)
        If x >= 0 Then
            Return 1 - tao
        Else
            Return tao - 1
        End If
    End Function

    '双阶乘函数
    Shared Function dfac(x%) As Long
        Dim y As Long
        y = 1
        For i = x To 1 Step -2
            y = y * i
        Next i
        Return y
    End Function

    '阶乘函数
    Shared Function fac(x%) As Long
        Dim y As Long
        y = 1
        For i = x To 1 Step -1
            y = y * i
        Next i
        Return y
    End Function
End Class
