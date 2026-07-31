<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<%
'=================================
'   狂舞游戏网站管理系统
'   www.kuang5.com
'  copyright(c)2007-2009 狂舞网络
'=================================
%>
document.write("<head><meta http-equiv='Content-Language' content='zh-cn'><meta http-equiv='Content-Type' content='text/html; charset=gb2312'></head>");

<%

Function glhtmlgg(title)
  title=replace(title,"&nbsp;","")
  title=replace(title,"""","'")
  title=replace(title,chr(10),"")
  title=replace(title,chr(13),"<br>")
  glhtmlgg=title
  set reg=nothing
End Function

id=trim(Request("id"))
if (not isNumeric(ID)) then
	id=""
end if
ttt=trim(request("ttt"))
if ttt="" then ttt=1
if id="0" then id=""
  sql="select * from [webgg]"

if id<>"" then sql=sql&" where id="&clng(id)
sql=sql&" order by id desc"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
while not rs.eof
  title=rs("title")
  content=glhtmlgg(rs("content"))
  addtime=rs("addtime")
  
if ttt="1" then%>
	document.write("<center><b><%=title%></b></center>");
	document.write("<center><hr size=1>加入时间：<%=formatdatetime(addtime,1)%></center>");
	document.write("<BR><%=content%>");
<% elseif ttt="0" then%>
	document.write("<BR><%=content%>");
<% elseif ttt="2" then%>
	document.write("<BR><%=title%>");
<% elseif ttt="3" then%>
	document.write("〖<%=title%>〗(<%=formatdatetime(addtime,1)%>)<%=glhtml(content)%>");	
<%end if
rs.movenext
wend

rs.close
set rs=nothing
conn.close
set conn=nothing
%>