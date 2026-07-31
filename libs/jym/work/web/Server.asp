<!--#include file = kuang5_conn.asp -->
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>Server</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
		<link href="images/style.css" type="text/css" rel="stylesheet">
	</HEAD>
	<body style="margin:0px 0px 0px 0px">


			<table width="100%" border="0" cellpadding="5" cellspacing="1" bgcolor=#F1E4C5>
<%

Function glhtmlgg(name)
  name=replace(name,"&nbsp;","")
  name=replace(name,"""","'")
  name=replace(name,chr(10),"")
  name=replace(name,chr(13),"<br>")
  glhtmlgg=name
  set reg=nothing
End Function




  sql="select * from [gamelist]"

if id<>"" then sql=sql&" where id="&clng(id)
sql=sql&" order by id desc"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
while not rs.eof
  name=rs("name")
  ip=glhtmlgg(rs("ip"))
  addtime=rs("addtime")
  ap=rs("ap")
  dlq=rs("dlq")
  color=rs("color")
 if ap="正常" then
   picap="Images/kuang5_Com_Zyxh_Index_019.gif"
  elseif ap="繁忙" then
   picap="images/kuang5_Com_07812_Index_030.gif"
 else
   picap="images/kuang5_Com_07812_Index_031.gif"
end if
%>
						<tr>
							<td height="80" align="left" valign="middle" style="font-size: 12px;color:#000">
							区名：<%=name%><br>
							区IP：<br>
							<a href='telnet://<%=ip%>'><span class='style5'><%=ip%></span></a><br>
							开放时间：<%=addtime%><br>
							状态：<img src="<%=picap%>" width="20" height="8">
							</td>
						</tr>
<%
	
	
rs.movenext
wend

rs.close
set rs=nothing
%>
			</table>

	</body>
</HTML>
