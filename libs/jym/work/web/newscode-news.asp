<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->

document.write("<head><meta http-equiv='Content-Language' content='zh-cn'><meta http-equiv='Content-Type' content='text/html; charset=gb2312'></head>");

<%


id=trim(request("id"))
nr=trim(request("nr"))
font=trim(request("font"))
nr=trim(request("nr"))
nrtop=trim(request("nrtop"))
nrcolor=trim(request("nrcolor"))
titlesize=trim(Request("titlesize"))
titleface=trim(Request("titleface"))
titlebold=trim(Request("titlebold"))
titlen=trim(Request("titlen"))
titlecolor=trim(Request("titlecolor"))
list=trim(Request("list"))
lm=trim(Request("lm"))
if lm="" then lm=0

if titlecolor="" then titlecolor="000000"
if titlen="" then titlen=30
titlen=int(titlen)
if titlebold="" then titlebold=100
if nrcolor="" then nrcolor="999999"
if nr="" then nr=0
if nrtop="" then nrtop=150
nrtop=int(nrtop)
if font="" then font=9
if titlesize="" then titlesize=font
path=config("path")

if id="" then id=0
if nr="" then nr=0
if list="" then list=1

if (not isNumeric(id)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数.');location.href='/';</Script>"
  response.end  
end if

if (not isNumeric(lm)) then
	lm=0
end if

  sql="select top "&list&" * from [news] where [sh]=1 "
  if id<>0 then sql=sql&" and [id]="&id&" "
  if lm<>0 then sql=sql&" and ([lm]='"&lm&"' or [lm2]='"&lm&"' or [lm3]='"&lm&"') " 
  sql=sql&" order by id desc "
  set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
  while not rs.eof
      newsid=rs("id")
      title=glhtml(rs("title"))
      title=titleb(title,titlen)
      title=replace(title,"""","")
      content=glhtml(rs("content"))
      for i=1 to 31
      	content=replace(content,chr(i),"")
      next
      content=glhtml(titleb(content,nrtop))
      %>
document.write("<a href=<%=path%><%=hrefID(NewsID,rs("filename"))%> target=_blank><font face='<%=titleface%>' style='font-size:<%=titlesize%>pt;font-weight:<%=titlebold%>;color:<%=titlecolor%>'><%=title%></font></a>");
      <%
      if nr="1" then
      	%>
document.write("<BR>　　<font color=<%=nrcolor%> style='font-size:<%=font%>pt'><%=content%></font><BR>");
      	<%
      end if
  rs.movenext
  wend
  rs.close
  set rs=nothing
  
conn.close:set conn=nothing
%>