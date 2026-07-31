<!--#include FILE="upload.inc"-->
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>无标题文档</title>
<style type="text/css">
<!--
.style1 {font-size: 12px}
-->
</style>
</head>
<body leftmargin="0" topmargin="0" bgcolor="#F1F3F5">
<%
dim upNum
upNum=request.cookies("www.kuang5.com")("upNum")
response.write "<FONT color=red>"&upNum&"</font>"
dim upload,file,formName,formPath,iCount,filename,fileExt
set upload=new upload_5xSoft ''建立上传对象
 formPath=upload.form("filepath")
 ''在目录后加(/)
set fso=Server.CreateObject ("Scripting.FileSystemObject")
 fpath=server.MapPath (""&formPath&"")
 if fso.FolderExists(fpath) then
  '文件夹存在
 else
  '文件夹不存在,则创建文件夹
  fso.createfolder(fpath)
end if
 if right(formPath,1)<>"/" then formPath=formPath&"/" 
iCount=0
for each formName in upload.file ''列出所有上传了的文件
 set file=upload.file(formName)  ''生成一个文件对象
 if file.filesize<100 then
 	response.write "<font size=2>请先选择你要上传的文件　[ <a href=# onclick=history.go(-1)>重新上传</a> ]</font>"
	response.end
 end if
'文件上传大小的限制 	
 if file.filesize>204800 then
 	response.write "<font size=2>文件大小超过了限制　[ <a href=# onclick=history.go(-1)>重新上传</a> ]</font>"
	response.end
 end if

 fileExt=lcase(right(file.filename,4))

 if fileEXT<>".gif" and fileEXT<>".jpg" and fileEXT<>".bmp" then
 	response.write "<font size=2>文件格式不正确　[ <a href=# onclick=history.go(-1)>重新上传</a> ]</font>"
	response.end
 end if 

 randomize
 ranNum=int(90000*rnd)+10000
 filename=formPath&year(now)&month(now)&day(now)&hour(now)&minute(now)&second(now)&ranNum&fileExt
 
' filename=formPath&year(now)&month(now)&day(now)&hour(now)&minute(now)&second(now)&file.FileName
 
 if file.FileSize>0 then         ''如果 FileSize > 0 说明有文件数据
  file.SaveAs Server.mappath(FileName)   ''保存文件
'  response.write file.FilePath&file.FileName&" ("&file.FileSize&") => "&formPath&File.FileName&" 成功!<br>"
 	if fileEXT=".gif" then
 	response.write "<script>parent.FrontPage_Form1.pic.value='/edit/"&FileName&"'</script>"
 	elseif fileEXT=".jpg" then
 	response.write "<script>parent.FrontPage_Form1.pic.value='/edit/"&FileName&"'</script>"
	elseif fileEXT=".bmp" then
 	response.write "<script>parent.FrontPage_Form1.pic.value='/edit/"&FileName&"'</script>"
	elseif fileEXT<>"" then
    response.write "<script>parent.FrontPage_Form1.pic.value='/edit/"&FileName&"'</script>"
	end if
 iCount=iCount+1
 end if
 set file=nothing
next
set upload=nothing  ''删除此对象

Htmend iCount&" 个文件上传结束!"

sub HtmEnd(Msg)
 set upload=nothing
 if upNum="" then upNum=1
 response.cookies("www.kuang5.com")("upNum")=upNum+1
 response.end
end sub
%>
</body>
</html>