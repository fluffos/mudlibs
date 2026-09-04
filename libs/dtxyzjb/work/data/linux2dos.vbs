'本vbs脚本用于消除linux下文本文件在windows下打开时的不可识别小黑块。
'Athor: fanyng

set objArgs = WScript.Arguments

'判断参数
IF objArgs.Count = 0 Then
     Wscript.echo "Usage: 把要转换的文件拖到此文件上"
     WScript.Quit
ElseIf objArgs.Count = 1 Then
     inFile = objArgs(0)
     outFile = Left(inFile,Len(inFile)-4)+"_out"
ElseIf objArgs.Count = 2 Then
     inFile = objArgs(0)
     outFile = objArgs(1)
End If

Const ForReading = 1, ForWriting = 2
Dim fso, Fin , Fout, str , id
id = 0

'创建文件对象
Set fso = CreateObject("Scripting.FileSystemObject")

Set Fin = fso.OpenTextFile( inFile , ForReading , False)
Set Fout = fso.OpenTextFile( outFile , ForWriting,True)

'读写文件开始
Do While Fin.AtEndOfStream <> True
        Fout.WriteLine Fin.ReadLine
Loop
Fin.Close
Fout.Close
