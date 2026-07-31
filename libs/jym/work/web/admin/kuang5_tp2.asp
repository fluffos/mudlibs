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
<title>&nbsp;</title>
<link rel="stylesheet" type="text/css" href="admin_style.css">
</head>
<%
id=trim(Request("id"))
up=trim(Request("up"))
down=trim(Request("down"))
tpid=trim(Request("tpid"))
delid=trim(Request("delid"))
editid=trim(Request("editid"))
saveid=trim(Request("saveid"))
tpxx=trim(Request("tpxx"))
endtime=trim(Request("endtime"))
DD=trim(Request("DD"))
sj=date()
eendtime=date()

sql="select * from [tp] where id="&tpid&" order by id desc"
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
if rs.recordcount<>0 then
	title=rs("title")
	endtime=rs("endtime")
end if
rs.close:set rs=nothing

if delid<>"" then
	conn.Execute "delete from [tptitle] where ID="&CInt(delid)
end if

if editid="" and saveid="" and tpxx<>"" then
	conn.Execute "insert into [tptitle] ([tpxx],[tpid],[tps]) values('"&tpxx&"',"&tpid&",0)"
	Response.Redirect "kuang5_tp2.asp?tpid="&tpid
elseif editid<>"" and saveid="" and tpxx="" then
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [tptitle] where id="&editid&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		etpxx=rs("tpxx")
	end if
	rs.close:set rs=nothing
elseif saveid<>"" and tpxx<>"" then
	conn.Execute "update [tptitle] set [tpxx]='"&tpxx&"' where id="&clng(saveid)
	Response.Redirect "kuang5_tp2.asp?tpid="&tpid
elseif id<>"" and up="1" then
	conn.Execute "update [tptitle] set [tps]=tps+1 where id="&clng(id)
elseif id<>"" and down="1" then
	conn.Execute "update [tptitle] set [tps]=tps-1 where id="&clng(id)
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [tptitle] where id="&id&" order by id desc",conn,1,3
	if rs.recordcount<>0 then
		if rs("tps")<0 then
			rs("tps")=0
			rs.update
		end if
	end if
	rs.close:set rs=nothing
end if
%>
<body>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr><th><%=title%></th></tr>
<tr><td class=tablerow>
<form method="POST" action="kuang5_tp2.asp?tpid=<%=tpid%>&saveid=<%=editid%>">
	选项：<input type="text" name="tpxx" size="40" value='<%=etpxx%>'> <input type="submit" value=" 保存 " name="B1">   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  <a href=kuang5_tp.asp><b>返回</b></a>
</form>
</td></tr></table>
<br><br>
	<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th align="center" width="467"><%=title%></th>
			<th align="center" width="115">投票数</th>
			<th align="center" width="101">操作</th>
		</tr>
<%

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [tptitle] where tpid="&tpid&" order by id asc",conn,1,1
while not rs.eof
%>
		<tr>
			<td class=tablerow width="467"><%=rs("tpxx")%></td>
			<td class=tablerow width="115">　<a href="kuang5_tp2.asp?tpid=<%=tpid%>&id=<%=rs("id")%>&up=1" title='加一个投票数'>↑</a><a href="kuang5_tp2.asp?tpid=<%=tpid%>&id=<%=rs("id")%>&down=1" title='减一个投票数'>↓</a>　<%=rs("tps")%></td>
			<td class=tablerow align=center width="101">
			<a href="kuang5_tp2.asp?editid=<%=rs("id")%>&tpid=<%=tpid%>">修改</a>　<a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href="kuang5_tp2.asp?delid=<%=rs("id")%>&tpid=<%=tpid%>">删除</a></td>
		</tr>
<%
rs.movenext
wend
rs.close:set rs=nothing
%>
	</table>


</body>

</html>
<%
conn.close:set conn=nothing
%>