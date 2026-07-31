<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<%
id=chkhtm(trim(request("id")))

if (not isNumeric(id)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数，请勿随意提交数据！');location.href='/';</Script>"
  response.end  
end if


set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [tp] where id="&id&" order by id asc",conn,1,1
if rs.recordcount<>0 then
	path=config("path")
	DD=rs("DD")
	id=rs("id")
	title=rs("title")
	EndTime=rs("Endtime")
	if DD=1 then
		Ftype="radio"
	else
		Ftype="checkbox"
	end if
	Response.Write "document.write(""<table border=0><form method='POST' name='haha' action='"&path&"JS-TP2.asp?tpid="&id&"' target=_blank><tr><td style='line-height:160%'>"");"
	Response.Write "document.write(""<font size=2 color=#FFFF00><b>"&rs("title")&"</b></font><BR>"");"
	
	set rs2 = Server.CreateObject("ADODB.RecordSet")
	rs2.Open "select * from [tptitle] where tpid="&rs("id")&" order by id asc",conn,1,1
	
	while not rs2.eof
	
	Response.Write "document.write(""<input type='"&Ftype&"' name='tps' id='"&rs2("id")&"' value='"&rs2("id")&"'>"");"
	Response.Write "document.write(""<font size=2 color=#FFFF00><label for='"&rs2("id")&"'>"&rs2("tpxx")&"</label></font><BR>"");"
	
	rs2.movenext
	wend
	
	%>
	
	document.write("<br>&nbsp;&nbsp;<img src='images/vote_button_001.gif' border='0' onclick=haha.submit()>&nbsp;&nbsp;　<input type='image' src='images/vote_button_002.gif' value=查看 onclick=window.open('<%=path%>js-tp2.asp?tpid=<%=id%>\')>");
	document.write("</td></tr></form></table>");
	<%
end if
rs.close:set rs=nothing
conn.close:set conn=nothing
%>