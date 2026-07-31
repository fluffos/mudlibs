<% 
'// Edit by rock
'// 2009.2.6

'yourip=Request.ServerVariables("REMOTE_ADDR")         '//取得访问者ip
'ip=left(yourip,13)                      '//取ip地址的前9位，这个为限制ip段做准备，这个值可以根据实际情况改
'If NOT ip="222.221.166.1" Then '//if判断，限制比较多的可以多用几个or
'response.write "Can not connect to server."
'response.write ip
'Else 
		'// 如果命令为 写入，则将信息写到指定的文件中 
		If LCase(Request.QueryString("1")&"")="1" Then 
		
		        strname = Request.Form("UserName")
		        '//取字段
		        str1 =left(strname,1)
		        str2 =left(strname,2)
						If str1 = "" or str2 = "" then
								'response.write "Can not connect to server."
								Response.ReDirect "http://www.kmmud.com/ty/index.html"
						else
		        		'// 如果没有路经就创建
		        		set fs=createobject("scripting.filesystemobject")
		        		MyFolder=server.mappath("data/"&str1&"/") 

				        If NOT fs.folderexists(MyFolder) then
				                fs.createfolder(MyFolder)
				        End If
				
				        If NOT fs.folderexists(MyFolder) then
				                response.write "Error:内部错误，请联系GM。"
				        End If
				
				        set fs=createobject("scripting.filesystemobject")
				        MyFolder=server.mappath("data/"&str1&"/"&str2&"/") 
				
				        If NOT fs.folderexists(MyFolder) then
				                fs.createfolder(MyFolder)
				        End If
		        End If
		
			If str1 = "" or str2 = "" then
'					response.write "Can not connect to server."
					Response.ReDirect "http://www.kmmud.com/ty/index.html"
			Else
					If NOT fs.folderexists(MyFolder) then
							response.write "Error:内部错误，请联系GM。"
					Else
							strpath = server.mappath("data/"&str1&"/"&str2) & "/" & strname
							'// 检查文件是否存在(避免重复注册)
							If fs.FileExists(strpath) then
									'// 转到注册失败
									Response.ReDirect "http://www.kmmud.com/ty/save-2.htm"
							Else
				           '// 调用写入指定的文件 
				           Call writeFile(strpath) 
				           '// 转到注册成功
				           Response.ReDirect "http://www.kmmud.com/ty/save-1.htm" 
							End If
							'// 释放掉 fs
							Set fs = nothing
		      End If 
		   End If
		        '// 写入指定的文件 
			Private Function writeFile(strFileName) 
				Dim oFSO,oTextStream,strContent 
				'// 创建FSO对象 
				Set oFSO = CreateObject("Scripting.FileSystemObject") 
				'// 创建一个文本文件 
				Set oTextStream = oFSO.CreateTextFile(strFileName) 
		
				'// 数据结构
				strContent = "UserName:" & Request.Form("UserName") & vbCrlf & _ 
				"oldpass:" & Request.Form("oldpass") & vbCrlf & _ 
				"quest:" & Request.Form("quest") & vbCrlf & _ 
				"ans:" & Request.Form("ans") & vbCrlf & _ 
				"num:" & Request.Form("num") & vbCrlf & _ 
				"qq:" & Request.Form("qq") & vbCrlf & _ 
				"email:" & Request.Form("email")
		
				'// 写入文件内容 
				oTextStream.Write strContent 
				oTextStream.Close 
		
				'// 释放对象 
				Set oTextStream = Nothing 
				Set oFSO = Nothing 
			End Function 
		'// 检查文件是否存在
		Else
		        temp = LCase(Request.QueryString("1")&"")
			strname = mid(temp,2,12)
		        '//取字段
		        str1 =left(strname,1)
		        str2 =left(strname,2)
		        set fs=createobject("scripting.filesystemobject")
			If str1 = "" or str2 = "" then
					'response.write "Can not connect to server."
					Response.ReDirect "http://www.kmmud.com/ty/index.html"
			else
					strpath = server.mappath("data/"&str1&"/"&str2&"/")
				
				        If NOT fs.folderexists(server.mappath("data/"&str1&"/")) then
				                'response.write "恭喜，该用户名可以注册。"
				                Response.ReDirect "http://www.kmmud.com/ty/save-3.htm"
					End If
				
					If NOT fs.folderexists(server.mappath("data/"&str1&"/"&str2&"/")) then
				                'response.write "恭喜，该用户名可以注册。"
				                Response.ReDirect "http://www.kmmud.com/ty/save-3.htm"
					End If
				
					strpath = server.mappath("data/"&str1&"/"&str2)& "/" & strname
				
					If NOT fs.FileExists(strpath) then
						'response.write "恭喜，该用户名可以注册。"
						Response.ReDirect "http://www.kmmud.com/ty/save-3.htm"
					Else
						'response.write "该用户已经存在。"
						Response.ReDirect "http://www.kmmud.com/ty/save-2.htm"
					End If
					'// 释放掉 fs
					Set fs = nothing
				End If
		End If
'End if
%> 