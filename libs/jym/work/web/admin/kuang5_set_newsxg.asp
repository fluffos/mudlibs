<%
'ON ERROR RESUME NEXT
if session("dj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->

<%
newsx=trim(request("newsx"))
pl=trim(request("pl"))
moreline=trim(request("moreline"))

kuang5gg=trim(request("kuang5GG"))
kuang5GGWZ=trim(request("kuang5GGWZ"))
plfb=trim(request("plfb"))
ggso=trim(request("ggso"))
ZuZiIP=trim(Request("ZuZiIP"))
lysh=trim(Request("lysh"))
lrySH=trim(Request("lrySH"))
wz=trim(request("wz"))
plsh=trim(request("plsh"))
WebEmail=trim(request("WebEmail"))
webname=trim(request("webname"))
Domain=trim(request("Domain"))
webtit=trim(request("webtit"))
Keyword=trim(request("Keyword"))
icp=trim(request("icp"))
kefu=trim(request("kefu"))

if instr(WebEmail,"@")=0 or instr(WebEmail,".")=0 then
	Response.Write "<script>alert('请正确填写EMAIL');</script> <meta http-equiv='refresh' content='0; url=javascript:window.history.go(-1);'>"
	Response.end
end if

if (not isNumeric(kuang5gg)) then
	kuang5gg=1
end if
if kuang5ggwz="" then kuang5ggwz=0

if newsx<>"" and PL<>"" and moreline<>"" then
	'conn.Execute "update [config] set [newsx]="&newsx&",[pl]="&pl&",[moreline]="&moreline&",[kuang5GG]="&kuang5GG&",[kuang5GGWZ]="&kuang5GGWZ&",[plfb]="&plfb&" "
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [config] order by id desc",conn,1,3

		rs("newsx")=newsx
		rs("pl")=pl
		rs("moreline")=moreline
		rs("kuang5gg")=kuang5gg
		rs("kuang5ggwz")=kuang5ggwz
		rs("plfb")=plfb&" "
		rs("ggso")=ggso
		rs("zuziip")=zuziip
		rs("lysh")=lysh
		rs("lrysh")=lrysh
		rs("plsh")=plsh
		rs("WebEmail")=WebEmail
		rs("webname")=webname
		rs("domain")=domain
		rs("webtit")=webtit
		rs("keyword")=keyword
		rs("icp")=icp
		rs("kefu")=kefu
		rs.update

	rs.close:set rs=nothing
	
	
end if
conn.close
set conn=nothing

Response.Redirect "kuang5_set.asp#"&wz
%>