<!--#include file = kuang5_conn.asp -->
<!--#include file = md5.asp -->
<html>

<head>
<!--#include file = language.asp -->
<!--#include file = titleb.asp -->
<title>网站后台登录</title>
</head>

<body>
<%

  sql = "select * from [admin]"
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
  if rs.recordcount=0 then
  	conn.Execute "insert into [admin] ([user],[pass],[dj]) values('admin','"&md5("admin")&"','1')"
  end if
  rs.close:set rs=nothing


userip = Request.ServerVariables("HTTP_X_FORWARDED_FOR")
If userip = "" Then userip = Request.ServerVariables("REMOTE_ADDR")

Function finddir(filepath)
	finddir=""
	for i=1 to len(filepath)
	if left(right(filepath,i),1)="/" or left(right(filepath,i),1)="\" then
	  abc=i
	  exit for
	end if
	next
	if abc <> 1 then
	finddir=left(filepath,len(filepath)-abc+1)
	end if
end Function

kuang5url=finddir(request.servervariables("URL"))
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [config]",conn,1,3
if rs.recordcount=0 then
   rs.addnew
end if

   rs("path")=kuang5url
   rs.update
   rs.close
   set rs=nothing

kuang5yzm=trim(request("kuang5yzm"))

if kuang5yzm="" then 
	Response.Redirect "login.asp?id=3"
end if

kuang5yzm=int(kuang5yzm)

if kuang5yzm<>session("kuang5yzm") then 
	Response.Redirect "login.asp?id=3"
end if

session("kuang5yzm")=""

if request("user")="" or request("pass")="" then

  conn.close
  set conn=nothing
  Response.Redirect "login.asp?id=0"
  
  else
  
  user=LCase(chkhtm(request("user")))
  pass=md5(chkhtm(trim(request("pass"))))
  
  sql = "select * from admin where [user]='"&user&"' and [pass]='"&pass&"'"
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
  
  if rs.recordcount=0 then
    blog=user&"登录系统后台失败。IP是："&userip&"。"
    addtime=year(now())&"-"&month(now())&"-"&day(now())&" "&hour(time())&":"&Minute(now())&":"&Second(now())
    conn.Execute "insert into [blog] ([content],[addtime]) values('"&blog&"','"&addtime&"')"
    conn.close
    set conn=nothing
    Response.Redirect "login.asp?id=1"
  end if
  
  session("kuang5__user")=rs("user")
  session("kuang5__pass")=pass
  session("dj")=rs("dj")
  Response.Cookies ("adminuser")=rs("user")
  Response.Cookies ("adminpass")=pass
  Response.Cookies ("admindj")=rs("dj")
  blog=rs("user")&"登录系统后台成功。IP是："&userip&"。"
  addtime=year(now())&"-"&month(now())&"-"&day(now())&" "&hour(time())&":"&Minute(now())&":"&Second(now())
  'Response.Write addtime
  'Response.end
  conn.Execute "insert into [blog] ([content],[addtime]) values('"&blog&"','"&addtime&"')"
  Response.Redirect "kuang5_index.asp"
  
end if
%>
</body>

</html>
<%
conn.close
set conn=nothing
%>