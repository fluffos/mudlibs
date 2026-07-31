<!--#include file = kuang5_conn.asp -->
<%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [config]",conn,1,1
if rs.recordcount<>0 then
  webname=rs("webname")
  Domain=rs("Domain")
  Webtit=rs("Webtit")
  ver=rs("ver")
  bank=rs("bank")
  shopgg=rs("shopgg")
  WebEmail=rs("WebEmail")
  keyword=rs("keyword")
  icp=rs("icp")
  kefu=rs("kefu")
end if
rs.close
set rs=nothing
%>
<!--#include file="newscode.asp"-->