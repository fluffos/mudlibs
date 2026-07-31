<%
if Request.Cookies("admindj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<html>

<head>
<!--#include file = language.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
</head>

<body topmargin="0" bgcolor="#ffffff" leftmargin="0" rightmargin="0" bottommargin="0" marginwidth="0" marginheight="0">

<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder"><tr><th colspan="3">HTML生成说明</th></tr>
		<tr><td width="398" class="TableRow2"> 1:每次在您后台添加/修改了网站内容后,请重新生成更新相关HTML文件.</td>
			<td class=tablerow width="348" align="center"> 2:生成HTML的好处:高安全、速度快、有利于搜索引擎收录</td>

		</tr>
	</table>
	<br><br>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
	<tr>
		<th>
		更新进度</th>
	</tr></table>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
		<td align="center" class=tablerow bgcolor="#EFEFEF">
<%
In_Url="/main.asp"
Out_Url="/index.html"

'核心代码请勿修改！
Do_Url = "http://"
Do_Url = Do_Url&Request.ServerVariables("SERVER_NAME")&"/"&In_Url
set http=Server.createobject("Msxml"&"2.XML"&"HTTP")
Http.open "GET",Do_Url,false
Http.send()
set objStream = Server.CreateObject("ADODB.St"&"ream")
objStream.type = 1
objStream.open
objstream.write http.responseBody
objstream.saveToFile server.mappath(Out_Url),2
objstream.close
%>

HTMl静态首页更新完毕....
</td>
  </tr></table>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
		<td align="center" class=tablerow bgcolor="#EFEFEF">
<%
In_Url="/ver.asp"
Out_Url="/ver.html"

'核心代码请勿修改！
Do_Url = "http://"
Do_Url = Do_Url&Request.ServerVariables("SERVER_NAME")&"/"&In_Url
set http=Server.createobject("Msxml"&"2.XML"&"HTTP")
Http.open "GET",Do_Url,false
Http.send()
set objStream = Server.CreateObject("ADODB.St"&"ream")
objStream.type = 1
objStream.open
objstream.write http.responseBody
objstream.saveToFile server.mappath(Out_Url),2
objstream.close
%>

HTMl静态游戏介绍页更新完毕....
</td>
  </tr></table>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
		<td align="center" class=tablerow bgcolor="#EFEFEF">
<%
In_Url="/down.asp"
Out_Url="/down.html"

'核心代码请勿修改！
Do_Url = "http://"
Do_Url = Do_Url&Request.ServerVariables("SERVER_NAME")&"/"&In_Url
set http=Server.createobject("Msxml"&"2.XML"&"HTTP")
Http.open "GET",Do_Url,false
Http.send()
set objStream = Server.CreateObject("ADODB.St"&"ream")
objStream.type = 1
objStream.open
objstream.write http.responseBody
objstream.saveToFile server.mappath(Out_Url),2
objstream.close
%>

HTMl静态游戏下载页更新完毕....
</td>
  </tr></table>

<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
		<td align="center" class=tablerow bgcolor="#EFEFEF">
<%
In_Url="/shop.asp"
Out_Url="/shop.html"

'核心代码请勿修改！
Do_Url = "http://"
Do_Url = Do_Url&Request.ServerVariables("SERVER_NAME")&"/"&In_Url
set http=Server.createobject("Msxml"&"2.XML"&"HTTP")
Http.open "GET",Do_Url,false
Http.send()
set objStream = Server.CreateObject("ADODB.St"&"ream")
objStream.type = 1
objStream.open
objstream.write http.responseBody
objstream.saveToFile server.mappath(Out_Url),2
objstream.close
%>

HTMl静态游戏商城页更新完毕....
</td>
  </tr></table>
	
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
		<td align="center" class=tablerow bgcolor="#EFEFEF">
<%
In_Url="/bank.asp"
Out_Url="/bank.html"

'核心代码请勿修改！
Do_Url = "http://"
Do_Url = Do_Url&Request.ServerVariables("SERVER_NAME")&"/"&In_Url
set http=Server.createobject("Msxml"&"2.XML"&"HTTP")
Http.open "GET",Do_Url,false
Http.send()
set objStream = Server.CreateObject("ADODB.St"&"ream")
objStream.type = 1
objStream.open
objstream.write http.responseBody
objstream.saveToFile server.mappath(Out_Url),2
objstream.close
%>

HTMl静态汇款方式页更新完毕....
</td>
  </tr></table>	
	
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
		<td align="center" class=tablerow bgcolor="#EFEFEF">
<%
In_Url="/tougao.asp"
Out_Url="/tougao.html"

'核心代码请勿修改！
Do_Url = "http://"
Do_Url = Do_Url&Request.ServerVariables("SERVER_NAME")&"/"&In_Url
set http=Server.createobject("Msxml"&"2.XML"&"HTTP")
Http.open "GET",Do_Url,false
Http.send()
set objStream = Server.CreateObject("ADODB.St"&"ream")
objStream.type = 1
objStream.open
objstream.write http.responseBody
objstream.saveToFile server.mappath(Out_Url),2
objstream.close
%>

HTMl静态玩家投稿页更新完毕....
</td>
  </tr></table>	
	
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
		<td align="center" class=tablerow bgcolor="#EFEFEF">
<%
In_Url="/Message.asp"
Out_Url="/Message.html"

'核心代码请勿修改！
Do_Url = "http://"
Do_Url = Do_Url&Request.ServerVariables("SERVER_NAME")&"/"&In_Url
set http=Server.createobject("Msxml"&"2.XML"&"HTTP")
Http.open "GET",Do_Url,false
Http.send()
set objStream = Server.CreateObject("ADODB.St"&"ream")
objStream.type = 1
objStream.open
objstream.write http.responseBody
objstream.saveToFile server.mappath(Out_Url),2
objstream.close
%>

HTMl静态玩家留言页更新完毕....
</td>
  </tr></table>

</body>

</html>
