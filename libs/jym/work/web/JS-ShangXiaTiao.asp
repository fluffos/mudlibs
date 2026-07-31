<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->

<%
id=trim(Request("id"))
newsid=id
if (not isNumeric(ID)) then
	id=0
end if

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id,lm,lm2,lm3 from [news] where id="&id&" order by id desc",conn,1,1
if rs.recordcount<>0 then
	lmid=rs("lm3")
	if lmid="" or lmid="0" then lmid=rs("lm2")
	if lmid="" or lmid="0" then lmid=rs("lm")
end if
rs.close:set rs=nothing
	
set rs2 = Server.CreateObject("ADODB.RecordSet")
rs2.Open "select * from [lm] where ID="&lmid&" order by id desc",conn,1,1
if rs2.recordcount<>0 then
	mbid=rs2("mb")
end if
rs2.close:set rs2=nothing

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select ID,updown from [xymb] where id="&mbid&" order by id desc",conn,1,1
if rs.recordcount<>0 then
	updown=rs("updown")
end if
rs.close:set rs=nothing

  if updown=0 then
    nr=replace(nr,"$$toptobottom$$","")
  else
    Set rs4 = Server.CreateObject("ADODB.RecordSet")
    rs4.Open "select top 1 id,lm,lm2,lm3,sh,filename,title,titlecolor from [news] where (lm2='"&lmid&"' or lm='"&lmid&"' or lm3='"&lmid&"') and id<"&newsid&" and sh=1 order by id desc",conn,1,1
    if rs4.recordcount<>0 then
	    uuu="上一条：<a href=../../../"&hrefID(rs4("id"),rs4("filename"))&"><font color="&rs4("titlecolor")&">"&rs4("title")&"</font></a><BR>"
	else
	    uuu="上一条：已经没有了<BR>"
	end if
    Set rs5 = Server.CreateObject("ADODB.RecordSet")
    rs5.Open "select top 1 id,lm,lm2,lm3,sh,filename,title,titlecolor from [news] where (lm2='"&lmid&"' or lm='"&lmid&"' or lm3='"&lmid&"') and id>"&newsid&" and sh=1 order by id asc",conn,1,1
    if rs5.recordcount<>0 then
	    uuu=uuu&"下一条：<a href=../../../"&hrefID(rs5("id"),rs5("filename"))&"><font color="&rs5("titlecolor")&">"&rs5("title")&"</font></a>"
	else
	    uuu=uuu&"下一条：已经没有了"
	end if
    nr=uuu
    rs4.close
    set rs4=nothing
    rs5.close
    set rs5=nothing
  end if
  
  
conn.close:set conn=nothing
%>
document.write("<meta http-equiv='Content-Type' content='text/html; charset=gb2312'>");
document.write("<%=nr%>");