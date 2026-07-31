<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->

document.write("<head><meta http-equiv='Content-Language' content='zh-cn'><meta http-equiv='Content-Type' content='text/html; charset=gb2312'></head>");

<%
x=trim(request("x"))
y=trim(request("y"))
w=trim(request("w"))
h=trim(request("h"))
n=trim(request("n"))
lm2=trim(request("lm2"))
lm=trim(request("lm"))
nr=trim(request("nr"))
nrtop=trim(request("nrtop"))
if nr="" then nr="0"
if nrtop="" then nrtop=100
nrtop=int(nrtop)
font=trim(request("font"))
zuo=trim(request("zuo"))
if zuo="" then zuo=1
if font="" then font=9
fy=trim(request("fy"))
hr=trim(request("hr"))
if hr="" then hr=0
if hr="1" then 
hhh="<hr size=1>"
end if
page=trim(request("page"))

if page="" then page=1
if fy="" then fy=0
if n="" then n=20
n=int(n)
open=trim(request("open"))
if open="0" then
  open="_top"
else
  open="_blank"
end if
if w="" then w=100
if h="" then h=100
if x="" then x=1
if y="" then y=1
x=int(x)
y=int(y)

xy=x*y

path=config("path")

if (not isNumeric(lm)) then
	lm=0
end if

sql = "select * from news where pic<>'' and sh=1 "
if lm<>"0" then sql=sql&" and (lm='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"') "
sql=sql&" order by ontop desc , updat desc , id desc"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
%>
document.write("<div align=center>");

<%
if rs.recordcount<>0 then

page=int(page)
rs.PageSize=xy
pagecount=rs.pagesize
if page<=0 then page=1
if request("page")="" then page=1
rs.AbsolutePage=page

for i=1 to pagecount
			for yyyy=1 to y	
%>
document.write("<table border=0 cellpadding=5 cellspacing=0 width=100% id=tableaasdaDF1>");
		document.write("<tr>");
			<%
			if rs.eof then exit for
			for xxxx=1 to x
			if n<>0 then
			  ttt="<BR><font color="&rs("titlecolor")&">"&titleb(rs("title"),n)&"</font>"
			end if
			title=rs("title")
			id=rs("id")
			if nr="1" and nrtop<>0 then
			  content=glhtml(rs("content"))
			  content=titleb(content,nrtop)
			  if zuo="0" then
			    zuo1="<td valign=top style='font-size:"&font&"pt'>"&content&"</td>"
			  elseif zuo="1" then
			    zuo2="<td valign=top style='font-size:"&font&"pt'>"&content&"</td>"
			  end if
			%>
				document.write("<%=zuo1%>");
			<%
			end if
			%>
			document.write("<td align=center style='font-size:<%=font%>pt;line-height=150%'><a href=<%=path%><%=hrefID(ID,rs("filename"))%> target='<%=open%>' title='<%=title%>'><img border=0 width=<%=w%> height=<%=h%> src=<%=rs("pic")%>><%=ttt%></a></td>");
				document.write("<%=zuo2%>");
			<%
			rs.movenext
			if rs.eof then 
			  exit for
			end if
			next
			if rs.eof then
			%>
			 document.write("</tr><%=hhh%></table>");
			<%			
			 exit for
			 
			 end if
			%>

		document.write("</tr><%=hhh%></table>");

<%
next
next

else
%>
document.write("暂无图片信息");
<%
end if
%>
document.write("</div><center>");
<%if rs.recordcount<>0 then
  if fy="1" then
  if page>1 then
 %>
 document.write("<a href=?page=1&lm=<%=lm2%>&x=<%=x%>&y=<%=y%>&w=<%=w%>&h=<%=h%>&open=<%=open%>&n=<%=n%>&nr=<%=nr%>&nrtop=<%=nrtop%>&zuo=<%=zuo%>&fy=<%=fy%>&hr=<%=hr%>&font=<%=font%>><font style='font-size:<%=font%>pt'>首页</font></a>　");
 document.write("<a href=?page=<%=page-1%>&lm=<%=lm2%>&x=<%=x%>&y=<%=y%>&w=<%=w%>&h=<%=h%>&open=<%=open%>&n=<%=n%>&nr=<%=nr%>&nrtop=<%=nrtop%>&zuo=<%=zuo%>&fy=<%=fy%>&hr=<%=hr%>&font=<%=font%>><font style='font-size:<%=font%>pt'>上一页</font></a>　");
 <%
  end if
  if page<rs.pagecount then
 %>
 document.write("<a href=?page=<%=page+1%>&lm=<%=lm2%>&x=<%=x%>&y=<%=y%>&w=<%=w%>&h=<%=h%>&open=<%=open%>&n=<%=n%>&nr=<%=nr%>&nrtop=<%=nrtop%>&zuo=<%=zuo%>&fy=<%=fy%>&hr=<%=hr%>&font=<%=font%>><font style='font-size:<%=font%>pt'>下一页</font></a>　");
 document.write("<a href=?page=<%=rs.pagecount%>&lm=<%=lm2%>&x=<%=x%>&y=<%=y%>&w=<%=w%>&h=<%=h%>&open=<%=open%>&n=<%=n%>&nr=<%=nr%>&nrtop=<%=nrtop%>&zuo=<%=zuo%>&fy=<%=fy%>&hr=<%=hr%>&font=<%=font%>><font style='font-size:<%=font%>pt'>尾页</font></a>　");
 <%
  end if
 %>
 document.write("<font style='font-size:<%=font%>pt'>共<%=rs.recordcount%>条　每页显示<%=pagecount%>条　共<%=rs.pagecount%>页　</font>");
 document.write("</center></table>");
<%
end if
end if

conn.close
set conn=nothing
%>