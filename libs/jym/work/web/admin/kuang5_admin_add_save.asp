<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = md5.asp -->

<%
'=================================
'   狂舞游戏网站管理系统
'   www.kuang5.com
'  copyright(c)2007-2009 狂舞网络
'=================================
%>
<%
lmid=trim(request("lmid"))
username=trim(request.Form("username"))
password=trim(request.Form("password"))
if password<>"" then password=md5(password)
id=trim(request("id"))

lmid=replace(lmid," ","")
lmid=lmid&","

if id="" then

sql = "select * from [admin] where [user]='"&username&"'"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,3
if rs.recordcount=0 then
  rs.addnew
  rs("user")=username
  if password<>"" then rs("pass")=password
  rs("lmid")=lmid
  rs("dj")=3
  rs.update
else 
  response.write "<BR><BR><BR><BR><BR><center><a href=javascript:history.back();>此用户名("&username&")已经存在!</a>"
  rs.close
  set rs=nothing
  conn.close
  set conn=nothing
  response.end
end if

elseif id<>"" then   '否则ID有值，不是空的

  sql = "select * from [admin] where [user]='"&username&"'"
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,2
if rs.recordcount<>0 then
  rs("user")=username
  if password<>"" then rs("pass")=password
  rs("dj")=3
  rs.update
end if

end if
rs.close
set rs=nothing
conn.close
set conn=nothing

Response.Redirect "kuang5_admin.asp"
%>

