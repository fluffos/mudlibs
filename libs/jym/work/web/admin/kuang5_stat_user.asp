

<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<head>
<meta http-equiv="Content-Language" content="zh-cn">
<!--#include file = language.asp -->
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<STYLE type="text/css">
<!--
a:link {text-decoration: none; font-family: AdobeSm; color: #000000 }
a:visited {text-decoration: none; color: #000000 }
A:hover {COLOR: green; FONT-FAMILY: "宋体,MingLiU"; TEXT-DECORATION: underline}
body {font-size: 9pt; font-family: 宋体,MingLiU, Arial;color: #000000}
TD {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000;line-height: 120%;table-layout:fixed;word-break:break-all}
p {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000}
input {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000}
body {margin-top: 0; margin-bottom: 0;margin-left:0;margin-right:0; color: #000000}
select {FONT-SIZE: 9PT;font-family: 宋体}
option {FONT-SIZE: 9pt;font-family: 宋体}
textarea {FONT-SIZE: 9pt;font-family: 宋体}
-->
</STYLE>
</head>
<%


y1=chkhtm(trim(request("y1")))
y2=chkhtm(trim(request("y2")))
m1=chkhtm(trim(request("m1")))
m2=chkhtm(trim(request("m2")))
kuang5=chkhtm(trim(request("kuang5")))

if (not isNumeric(y1)) then
	y1=2000
end if

if (not isNumeric(y2)) then
	y2=year(now())
end if

if (not isNumeric(m1)) then
	m1=1
end if

if (not isNumeric(m2)) then
	m2=month(now())
end if

if (not isNumeric(kuang5)) then
	kuang5=0
end if

if (not isDate(y2&"-"&m2&"-31")) then
	ri=30
else
	ri=31	
end if

if (not isDate(y2&"-"&m2&"-30")) then
	ri=29
end if

if (not isDate(y2&"-"&m2&"-29")) then
	ri=28
end if

ymd1=y1&"-"&m1&"-1"
ymd2=y2&"-"&m2&"-"&ri

ymd1=formatdatetime(ymd1,0)
ymd2=formatdatetime(ymd2,0)

ChaM=datediff("d",ymd1,ymd2)

if clng(Cham)<1 then 
	Response.Write "<script>alert('日期选择不正确！');</script> <meta http-equiv='refresh' content='0; url=javascript:window.history.go(-1);'>" 
	Response.end
end if

CHAM=replace(CHAM,"-","")+1

Response.flush 
'Response.end



set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [admin]  order by id desc",conn,1,1
while not rs.eof
	username=rs("user")
	
	SQL="select id,adduser,[time] from [news] where adduser='"&username&"' and [time]>#"&ymd1&"# and [time]<#"&ymd2&"# order by id desc"
	set rs2 = Server.CreateObject("ADODB.RecordSet")
	'Response.Write SQL&"<br>"
	rs2.Open SQL,conn,1,1

	conn.Execute "update [admin] set [NewsSL]="&rs2.recordcount&" where [user]='"&username&"' "
	
	rs2.close:set rs2=nothing
rs.movenext
wend
rs.close:set rs=nothing
%>
<body>

<div align="center">
	<table border="0" width="760" id="table1" cellspacing="0" cellpadding="0">
		<tr>
			<td>　</td>
		</tr>
		<tr>
			<td>
			<p align="center"><b><font style="font-size: 17pt;line-height:160%">所有用户文章添加排行榜</font></b></td>
		</tr>
		<tr>
			<td>　</td>
		</tr>
		<form method="get" action="?kuang5=1">
		<tr>
			<td align=center>时间段显示
			
				<select size="1" name="y1">
				<%
				for i=2000 to year(now())
				%>
				<option <% if clng(y1)=clng(i) then Response.Write " selected "%>><%=i%></option>
				<%
				next
				%>
				</select>年

				<select size="1" name="m1">
				<%
				for i=1 to 12
				%>
				<option <% if clng(m1)=clng(i) then Response.Write " selected "%>><%=i%></option>
				<%
				next
				%>
				</select>月 到 
				
				<select size="1" name="y2">
				<%
				for i=2000 to year(now())
				%>
				<option <% if clng(y2)=clng(i) then Response.Write " selected "%>><%=i%></option>
				<%
				next
				%>
				</select>年

				<select size="1" name="m2">
				<%
				for i=1 to 12
				%>
				<option <% if clng(m2)=clng(i) then Response.Write " selected "%>><%=i%></option>
				<%
				next
				%>
				</select>				
				<input type="submit" value="搜索"><input type='button' value='显示所有' onclick="javascript:location.href='?'">
			
			</td>
		</tr>
		</form>
		
		<tr>
			<td>　</td>
		</tr>
	</table>
</div>

<div align="center">
	<table border="1" cellpadding="3" width="760" id="table2" style="border-collapse: collapse" bordercolor="#C0C0C0" cellspacing="0">
		<tr>
			<td background="../images/bj5.jpg" align="center"><b>
			<font color="#FFFFFF">用　户</font></b></td>
			<td background="../images/bj5.jpg" align="center"><b>
			<font color="#FFFFFF">文章文章数量</font></b></td>
		</tr>
		<%
		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [admin]  order by NewsSL desc , id desc",conn,1,1
		while not rs.eof
		%>
		<tr>
			<td><%=rs("user")%></td>
			<td align=center>
				<%
						Response.Write "共有"&rs("Newssl")&"篇，"
						set rs2 = Server.CreateObject("ADODB.RecordSet")
						rs2.Open "select adduser,id,sh from [News] where adduser='"&rs("user")&"'  and [time]>#"&ymd1&"# and [time]<#"&ymd2&"# and sh=2 order by id desc",conn,1,1
						Response.Write "有"&rs2.recordcount&"篇未审核"
						rs2.close:set rs2=nothing
				%>
			</td>
		</tr>
		<%
		rs.movenext
		wend
		rs.close:set rs=nothing
		%>
	</table>
</div>

</body>

</html>
<%
conn.close
set conn=nothing
%>