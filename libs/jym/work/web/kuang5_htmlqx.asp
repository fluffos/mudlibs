
<%
Server.ScriptTimeOut = 600

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
<!--#include file = language.asp -->

</head>
<body>
<%
lm=chkhtm(trim(request("lm")))
html=1
iii=0
jjj=0
if (not isNumeric(lm)) then
  Response.Write "<Script Language=JavaScript>alert('栏目参数错误或有非法字符或没指定参数，请勿随意提交数据！');</Script>"
  response.end  
end if
set rshtml = Server.CreateObject("ADODB.RecordSet")
rshtml.Open "select * from [News] where ( LM='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"' ) and sh=1 order by id desc",conn,1,1
while not rshtml.eof
	filename=rshtml("filename")
	if filename<>"0" then
		sdDel(filename)
		conn.Execute "update [news] set [filename]='0',[html]=0 where id="&clng(rshtml("id"))
		iii=iii+1
	else
		jjj=jjj+1
	end if
	
rshtml.movenext
wend
rshtml.close:set rshtml=nothing
%>
</body>
<script>alert('共有文章<%=iii+jjj%>条，取消静态文章<%=iii%>条');</script>
<meta http-equiv='refresh' content='0; url=javascript:window.history.go(-1);'>
</html>

<%
conn.close:set conn=nothing
%>