

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
  conn.Execute = "delete from admin where id="&id
end if

conn.close
set conn=nothing

Response.Redirect "kuang5_admin.asp"
%>