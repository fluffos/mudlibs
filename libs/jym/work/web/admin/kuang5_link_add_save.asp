
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<html>

<head>
<!--#include file = language.asp -->
<title>网站名称</title>
<style>
<!--
a:link       { font-size: 10.5pt; font-family: 宋体; color: #0066CC;text-decoration: none; }
a:visited    { color: #0066CC; font-family: 宋体; font-size: 10.5pt;text-decoration: none; }
a:hover      { font-size: 10.5pt; font-family: 宋体; color: #0066CC;TEXT-DECORATION: underline; }
body         { font-family: 宋体; color: #000000; font-size: 10.5pt }
p            { color: #000000; font-family: 宋体; font-size: 10.5pt }
td           { font-size: 10.5pt; font-family: 宋体; color: #000000 }
input           { font-size: 10.5pt; font-family: 宋体; color: #000000 }
-->
</style>
</head>

<body>

<%
if request("linkname")<>"" and request("url")<>"" then

  if request("id")="" then

  sql = "select top 1 * from link"
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,3
  
  rs.addnew
  
 else
 
  sql = "select * from link where id="&request("id")
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,3
   
end if


  rs("linkname")=request("linkname")
  rs("url")=trim(request("url"))
  rs("logo")=trim(request("logo"))
  rs("js")=trim(request("js"))
  rs.update
  
  rs.close
  set rs=nothing
end if
%>
</body>
<%
conn.close
set conn=nothing


Response.Redirect "kuang5_link.asp"
%>
</html>