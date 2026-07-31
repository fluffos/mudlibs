<!--#include file="kuang5_h.asp"-->
<!--#include file="head.asp"-->
<!--#include file = titleb.asp -->
<%
'ON ERROR RESUME NEXT
path=finddir(request.servervariables("URL"))
lm=trim(request("lm"))
if lm="" then lm=trim(Request("lm2"))
page=trim(request("page"))
if page="" then page=1
if lm="" then lm=0

if lm2="" then lm2=lm
if lm="" then lm=lm2
if lm2="" then lm2=0

if (not isNumeric(lm)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数，请勿随意提交数据！');</Script>"
  response.end  
end if

function pictulist()
%>
<table width="98%" border="0" cellpadding="5" cellspacing="1">
  <tr>
    <td><%=shopgg%></td>
  </tr>
</table>

<%
end function

	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [lm] where id="&lm&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		mbid=rs("mb")
		lmname="游戏商城"
	else
		set rs2 = Server.CreateObject("ADODB.RecordSet")
		rs2.Open "select * from [lm] order by id asc",conn,1,1
		if rs2.recordcount<>0 then
			mbid=rs2("mb")
		end if
		rs2.close:set rs2=nothing
	end if
	rs.close:set rs=nothing
	if mbid="" then mbid=0
	
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select id,listtum from [xymb] where id="&mbid&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		listtum=rs("listtum")
	else
		Response.Write "<BR><BR><BR><center>对不起，系统不正确！</center>"
		conn.close:set conn=nothing
		Response.end
	end if
	rs.close:set rs=nothing
	
	if instr(listtum,"$$Piclist$$")=0 then
		Response.Write "<BR><BR><BR><center>对不起，后台系统不正确，没有找到！</center>"
	else
			 listtum=replace(listtum,"$$kefu$$",kefu)	
			 listtum=replace(listtum,"$$Columns$$","游戏商城")
			 listtum=replace(listtum,"$$Path$$",lmaa())
			 listtum=replace(listtum,"$$LMID$$",lm)
		     listtum=split(listtum,"$$Piclist$$")

		     response.write listtum(0)
		     Response.Write pictulist()
		     Response.Write listtum(1)		
	end if
%>
<!--#include file="foot.asp"-->
<%
conn.close
set conn=nothing
%>