Imports subgrade_design.calculate_fun
Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim t#()
        t = cal(5, 0.9544, 0)
        Debug.WriteLine(t(0))
    End Sub

End Class
