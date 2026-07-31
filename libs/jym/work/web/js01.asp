<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->

<%
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id from [news] order by id desc",conn,1,1
%>
document.write("文章总数：<%=rs.recordcount%><BR>");
<%
rs.close:set rs=nothing
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id,pic from [news] where pic is not null",conn,1,1
%>
document.write("图片文章：<%=rs.recordcount%><BR>");
<%
rs.close:set rs=nothing
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id from [newspl]",conn,1,1
%>
document.write("评论总数：<%=rs.recordcount%><BR>");
<%
rs.close:set rs=nothing
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id,hit from [news]",conn,1,1
while not rs.eof
  hit=hit+rs("hit")
rs.movenext
wend
%>
document.write("阅读总数：<%=hit%><BR>");
<%
rs.close:set rs=nothing

conn.close
set conn=nothing
%>