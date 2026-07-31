<!--#include file = kuang5_chk.asp --><head>
<!--#include file = language.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
</head>
<%
'=================================
'   狂舞游戏网站管理系统
'   www.kuang5.com
'  copyright(c)2007-2009 狂舞网络
'=================================
%>
<!--#include file = kuang5_conn.asp -->

<%
sql = "select * from [admin] where [user]='"&session("kuang5__user")&"'"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1

%>


<% if Request.Cookies("admindj")=1 then %>
<div align="center">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2"  class="tableBorder">
<tr><th align="left" colspan="4">管理员管理</th></tr>
<tr>
  <td class=TableRow><img src="images/s.gif" width="7" height="9" border=0 align=absmiddle><a href="kuang5_admin.asp">管理员管理</a>&nbsp;</td>
  <td class=TableRow><img src="images/s.gif" width="7" height="9" border=0 align=absmiddle><a href="kuang5_admin_add.asp">增加录入人员</a>&nbsp;</td>
  <td class=TableRow><img src="images/s.gif" width="7" height="9" border=0 align=absmiddle><a href="kuang5_admin_sh_add.asp">增加审核员</a>&nbsp;</td>
  <td class=TableRow><img src="images/s.gif" width="7" height="9" border=0 align=absmiddle><a href="kuang5_stat_user.asp" >查看用户文章排名</a>&nbsp;</td>
  </tr>
</td></tr>
</table>
</div>
<table border=0><tr><td height=3></td></tr></table>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th>&nbsp;管理员名称</th>
			<th>&nbsp;管理权限</th>
			<th>&nbsp;相关操作</th>
		</tr>
<%
sql = "select * from admin "
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
while not rs.eof
%>
		<tr>
			<td class=TableRow width="215"><%=rs("user")%>
			<%
			  Set rs4 = Server.CreateObject("ADODB.RecordSet")
			  rs4.Open "select * from [news] where adduser='"&rs("user")&"' order by id desc",conn,1,1
			  Response.Write "("&rs4.recordcount&"篇)"
			  
			  if rs("dj")="3" then Response.Write "<font color=red>[录入员]</font>"
			  if rs("dj")="2" then Response.Write "<font color=blue>[审核员]</font>"
			   if rs("dj")="1" then Response.Write "<font color=blue>[管理员]</font>"
			%>
		  </td>
			<td class=TableRow width="307" align=center>
			<%
			if rs("dj")<>1 then
			lmid=rs("lmid")&","
			nr=split(lmid,",")
			'Response.Write ubound(nr)
			For i=0 to ubound(nr)
			  aaa=nr(i)
			  if aaa="" then aaa=0
			  sql3 = "select * from lm where id="&aaa
			  Set rs3 = Server.CreateObject("ADODB.RecordSet")
			  rs3.Open sql3,conn,1,1
			  if rs3.recordcount<>0 then
			     Response.Write rs3("lm")&rs3("lm2")&rs3("lm3")&","
			  end if
			  rs3.close
			  set rs3=nothing
			next
			%>
						<%else%>
			所有权限
			<%end if%>
		  　</td>
			
			<td class=TableRow width="216" align=center>
			<%if rs("dj")<>1 then%>
			<a href="kuang5_admin_edit.asp?id=<%=rs("id")%>">设置权限</a>　<a href="kuang5_admin_editpass.asp?id=<%=rs("id")%>">修改密码</a>　<a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href="kuang5_admin_del.asp?id=<%=rs("id")%>">删除</a>
				        <%else%>
						　<a href="kuang5_admin_editpass.asp?id=<%=rs("id")%>">修改密码</a>
		  <%end if%></td>
			
		</tr>
<%
rs.movenext
wend
%>
	</table>
<% end if %>

<%
conn.close
set conn=nothing
%>