<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<%

id=int(chkhtm(trim(request("id"))))
action=trim(request("action"))
username=chkhtm(trim(request("username")))
content=chkhtm(trim(request("content")))
addtime=date()

plsh=config("plsh")

if (not isNumeric(plsh)) then
   plsh=0
end if

userip = Request.ServerVariables("HTTP_X_FORWARDED_FOR")
If userip = "" Then userip = Request.ServerVariables("REMOTE_ADDR")

if id<>"" and username<>"" and content<>"" then
  conn.Execute = "insert into newspl (username,content,addtime,ip,newsid,sh) values('"&username&"','"&content&"','"&addtime&"','"&userip&"',"&id&","&plsh&")"
end if

if plsh="0" then
	Response.Write "<script>alert('已经提交成功，请等待工作人员审核！');</script>"
end if

filename="0"
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id,filename from [News] where ID="&ID&" order by id desc",conn,1,1
if rs.recordcount<>0 then
	filename=rs("filename")
end if
rs.close:set rs=nothing

url=hrefID(ID,filename)

if action="" then
	Response.Write "<META http-equiv='refresh' CONTENT='0;url=newspl.asp?id="&id&"'>"
else
	Response.Write "<META http-equiv='refresh' CONTENT='0;url="&url&"'>"
end if

conn.close
set conn=nothing
%>