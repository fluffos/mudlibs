<!--#include file = kuang5_chk.asp -->
<head>
<!--#include file = language.asp -->
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
</head>

<!--#include file = kuang5_conn.asp -->
<!--#include file = md5.asp -->

<%
username=trim(request("username"))
password=md5(trim(request("password")))
id=trim(request("id"))

if username<>"" or password<>"" then

 sql = "select * from admin where id="&id
 Set rs = Server.CreateObject("ADODB.RecordSet")
 rs.Open sql,conn,1,2
 rs("user")=username
 rs("pass")=password
 
 rs.update
 rs.close
 set rs=nothing
 
end if

conn.close
set conn=nothing
response.write "<BR><BR><BR><Center><a href=kuang5_admin.asp>修改成功！返回</a>"
%>
<%
'=================================
'   狂舞游戏网站管理系统
'   www.kuang5.com
'  copyright(c)2007-2009 狂舞网络
'=================================
%>