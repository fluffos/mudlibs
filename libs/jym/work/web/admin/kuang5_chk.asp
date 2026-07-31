<%
function chkh(stra)
  stra=replace(stra,"<","&lt;")
  stra=replace(stra,">","&gt;")
  stra=replace(stra,"'","")
  stra=replace(stra,"(","（")
  stra=replace(stra,")","）")
  stra=replace(stra,";","；")
  stra=replace(stra,",","，")
  stra=replace(stra,"%","％")
  stra=replace(stra,"+","＋")
  chkh=stra
end function
session("kuang5__user")=chkh(Request.Cookies("adminuser"))
session("kuang5__pass")=chkh(Request.Cookies("adminpass"))
session("dJ")=chkh(Request.Cookies("admindj"))

adminuser=chkh(Request.Cookies("adminuser"))
adminpass=chkh(Request.Cookies("adminpass"))
admindj=chkh(Request.Cookies("admindj"))

if adminuser="" or adminpass="" then
  Response.Redirect "login.asp?id=8"
end if
%><!--#include file = kuang5_conn.asp -->

<%


user=chkh(trim(session("kuang5__user")))
pass=adminpass

sql = "select * from admin where [user]='"&adminuser&"' and [pass]='"&adminpass&"'"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
if rs.recordcount=0 then

  Response.Cookies ("adminuser")=""
  Response.Cookies ("adminpass")=""
  Response.Cookies ("admindj")=""
  Response.Redirect "login.asp?id=8"
else
	Response.Cookies ("admindj")=rs("dj")
	session("dJ")=rs("dj")
end if
rs.close
set rs=nothing
conn.close
set conn=nothing
%>