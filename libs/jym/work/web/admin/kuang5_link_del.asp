
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->

<%
  if request("id")<>"" then
  id=request("id")
sql = "delete from link where id="&id
conn.Execute(sql)
response.redirect "kuang5_link.asp"


end if
%>