<%
if Request.Cookies("admindj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<html>

<head>
<meta http-equiv="Content-Language" content="zh-cn">
<!--#include file = language.asp -->
<title></title>
<link rel="stylesheet" type="text/css" href="admin_style.css">
</head>
<%
delid=trim(Request("delid"))
editid=trim(Request("editid"))
saveid=trim(Request("saveid"))
title=trim(Request("title"))
endtime=trim(Request("endtime"))
DD=trim(Request("DD"))
sj=date()
eendtime=date()

if delid<>"" then
	conn.Execute "delete from [tp] where ID="&CInt(delid)
	conn.Execute "delete from [tptitle] where tpID="&CInt(delid)
end if

if editid="" and saveid="" and title<>"" and DD<>"" then
	conn.Execute "insert into [tp] ([title],[dd],[addtime],[endtime]) values('"&title&"','"&dd&"','"&sj&"','"&endtime&"')"
elseif editid<>"" and saveid="" and title="" and dd="" then
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [tp] where id="&editid&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		etitle=rs("title")
		eendtitle=rs("endtime")
		DD=rs("DD")
	end if
	rs.close:set rs=nothing
elseif saveid<>"" and title<>"" and DD<>"" then
	conn.Execute "update [tp] set [title]='"&title&"',[DD]='"&DD&"',endtime='"&endtime&"' where id="&clng(saveid)
end if
%>
<body>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
<th colspan=2 align="left">
&nbsp;添加/修改投票调查</th>
</tr>
<tr>
<td class=tablerow>
<form method="POST" action="kuang5_tp.asp?saveid=<%=editid%>">
	&nbsp;标题：</td><td class=tablerow><input type="text" name="title" size="40" value='<%=etitle%>'> <select size="1"  name="DD">
	<option value="1">单项选择</option>
	<option value="2">多项选择</option></td></tr><tr><td class=tablerow>
	</select>&nbsp;结束时间：</td><td class=tablerow><input type="text" name="endtime" value='<%=eendtime+7%>' size="20"></td></tr><tr><td class=tablerow>&nbsp;</td><td class=tablerow> <input type="submit" value="保存后再增加选项" name="B1">
</form>
</td></tr></table>
<br><br>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th align="center" width="467">投票标题</td>
			<th align="center" width="76">投票数</td>
			<th align="center" width="141">操作</td>
		</tr>
<%
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [tp] order by id asc",conn,1,1
while not rs.eof
%>
		<tr>
			<td class=tablerow width="467">
			<%
				DD=rs("DD")
				if DD=1 then 
					Response.Write "[单项选择]"
				else
					Response.Write "[多项选择]"
				end if
			%>
			<%=rs("title")%></td>
			<td class=tablerow width="76" align=center>
				<%	
					set rssum = Server.CreateObject("ADODB.RecordSet")
					rssum.Open "select sum(tps) as f_sum from [tptitle] where tpid="&rs("id")&" ",conn,1,1
					Response.Write rssum(0)
					rssum.close:set rssum=nothing
				%>
			</td>
			<td class=tablerow align=center width="141">
			<a href="kuang5_tp2.asp?tpid=<%=rs("id")%>">可选择项</a>　<a href="kuang5_tp.asp?editid=<%=rs("id")%>">修改</a>　<a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href="kuang5_tp.asp?delid=<%=rs("id")%>">删除</a></td>
		</tr>
<%
rs.movenext
wend
rs.close:set rs=nothing
%>
	</table>
<center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
</table></center>
</body>

</html>
<%
conn.close:set conn=nothing
%>