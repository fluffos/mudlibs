<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<%

webxgnews=trim(Request("xgnews"))
newsid=trim(Request("id"))

if (not isNumeric(NewsID)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数，请勿随意提交数据！');</Script>"
  response.end  
end if

Set xgrs = Server.CreateObject("ADODB.RecordSet")
xgrs.Open "select top 10 * from [news] where ( title like '%"&webxgnews&"%' or xgnews like '%"&webxgnews&"%' ) and id<>"&newsid&" order by id desc",conn,1,1

while not xgrs.eof
	xgnews=xgnews + "·<a href=../../../"&hrefID(xgrs("id"),xgrs("filename"))&" title='"&xgrs("title")&"'>"&xgrs("title")&"</a><BR>"
	xgrs.movenext
wend

if xgrs.recordcount=0 then xgnews="没有相关信息"
xgrs.close:set xgrs=nothing

conn.close:set conn=nothing
%>

document.write("<%=xgnews%>");