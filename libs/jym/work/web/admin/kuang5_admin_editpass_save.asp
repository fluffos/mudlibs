

<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = md5.asp -->
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
<p>　</p>
<p align="center">　</p>

<%
id=trim(request("id"))
username=trim(request("username"))
password=md5(trim(request("password")))

if id<>"" then
sql = "select * from admin where id="&id
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,2
if rs.recordcount<>0 then
   rs("user")=username
   rs("pass")=password
   rs.update  
end if

rs.close
set rs=nothing

end if

conn.close
set conn=nothing

Response.Redirect "kuang5_admin.asp"
%>