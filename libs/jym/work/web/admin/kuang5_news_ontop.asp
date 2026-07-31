
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->

<%
ontop=cint(trim(request("ontop")))
id=cint(trim(request("id")))
title=trim(request("title"))
lm=trim(request("lm"))
page=trim(request("page"))

if id<>"" then
 
 sql = "update news set ontop="&ontop&" where id="&id
 response.write sql

 conn.Execute(sql)
end if

conn.close
set conn=nothing
Response.Redirect "kuang5_news_list.asp?page="&page&"&title="&title&"&lm="&lm
%>