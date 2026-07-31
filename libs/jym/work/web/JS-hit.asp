<!--#include file = kuang5_conn.asp -->
<%
NewsID=trim(Request("ID"))

if (not isNumeric(newsid)) then
  newsid=0
end if

conn.Execute "update [news] set [hit]=hit+1 where id="&clng(newsid)

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id,hit from [news] where id="&newsid&" order by id desc",conn,1,1
if rs.recordcount<>0 then
	hit=rs("hit")
end if	
rs.close:set rs=nothing

conn.close:set conn=nothing
%>

document.write("<%=hit%>");