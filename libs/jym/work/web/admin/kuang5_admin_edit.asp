

<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<style>
<!--
a:link       { font-size: 9pt; font-family: 宋体; color: #000000;text-decoration: none; }
a:visited    { color: #000000; font-family: 宋体; font-size: 9pt;text-decoration: none; }
a:hover      { font-size: 9pt; font-family: 宋体; color: #000000;TEXT-DECORATION: underline; }
body         { font-family: 宋体; color: #000000; font-size: 9pt }
p            { color: #000000; font-family: 宋体; font-size: 9pt }
td           { font-size: 9pt; font-family: 宋体; color: #000000 }
input        { font-size: 9pt; font-family: 宋体; color: #000000 }

-->
</style>
<head>
<!--#include file = language.asp -->
</head>
<%
id=trim(request("id"))
if id<>"" then
sql = "select * from admin where id="&id
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
if rs.recordcount<>0 then
  username=rs("user")
  lmid=rs("lmid")
end if
rs.close
set rs=nothing

end if
%>

<form method="POST" action="kuang5_admin_edit_save.asp?id=<%=id%>" onsubmit="return FrontPage_Form1_Validator(this)" language="JavaScript" name="FrontPage_Form1">
	<div align="center">
		　<p><a href=javascript:history.back();>返回</a></p>
		<table border="1" width="80%" id="table1" cellspacing="0" cellpadding="7" style="border-collapse: collapse" bordercolor="#C0C0C0">
			<tr>
				<td align="center" colspan="2">设置<%=username%>栏目</td>
			</tr>
			<tr>
				<td width="127" align="center">以有栏目权限</td>
				<td>
				
			   编号是:<%=lmid%></td>
			</tr>
			<tr>
				<td width="127" align="center">栏　目</td>
				<td>
				
				<%
				djid=lmid
				sql = "select * from lm where lm<>''"
				Set rs = Server.CreateObject("ADODB.RecordSet")
				rs.Open sql,conn,1,1
				while not rs.eof
				       ccc=""
					   nr=split(djid,",")
					   For i=0 to ubound(nr)
					        aaa=nr(i)
					        if aaa="" then aaa=0
				        if clng(aaa)=clng(rs("id")) then ccc=" checked "				        
				       next
				    'response.write "<BR><B>"&rs("lm")&"<font color=999999>(编号:"&rs("id")&")</font></b><br>"
				    Response.Write "<input "&ccc&" type=checkbox name=lmid value="&rs("id")&" id="&rs("id")&"><label for="&rs("id")&">"&rs("lm")&"<font color=999999>(编号:"&rs("id")&")</font></label><BR>"

				    sql2 = "select * from lm where lmid='"&rs("id")&"'"
				    Set rs2 = Server.CreateObject("ADODB.RecordSet")
				    rs2.Open sql2,conn,1,1
				    while not rs2.eof
				       ccc=""
					   nr=split(djid,",")
					   For i=0 to ubound(nr)
					        aaa=nr(i)
					        if aaa="" then aaa=0
				        if clng(aaa)=clng(rs2("id")) then ccc=" checked "				        
				       next
				        Response.Write "　<input "&ccc&" type=checkbox name=lmid value="&rs2("id")&" id="&rs2("id")&"><label for="&rs2("id")&">"&rs2("lm2")&"<font color=999999>(编号:"&rs2("id")&")</font></label><BR>"
				        Set rs3 = Server.CreateObject("ADODB.RecordSet")
				        rs3.Open "select * from [lm] where lmid='"&rs2("id")&"' order by id asc",conn,1,1
				        while not rs3.eof
				     	  ccc=""
					 	  nr=split(djid,",")
					 	  For i=0 to ubound(nr)
					 	       aaa=nr(i)
					 	       if aaa="" then aaa=0
				     	   if clng(aaa)=clng(rs3("id")) then ccc=" checked "				        
				     	  next
				        	Response.Write "　　　<input "&ccc&" type=checkbox name=lmid value="&rs3("id")&" id="&rs3("id")&"><label for="&rs3("id")&">"&rs3("lm3")&"<font color=999999>(编号:"&rs3("id")&")</font></label><BR>"
				        rs3.movenext
				        wend
				    rs2.movenext
					wend
				rs.movenext
				wend
				%>
				　</td>
			</tr>
	  </table>
	</div>
	<p align="center"><input type="submit" value=" 提 交 " name="B1">　&nbsp;　<input type="reset" value=" 重 置 " name="B2"></p>
</form>