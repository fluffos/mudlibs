<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
document.write("<head><meta http-equiv='Content-Language' content='zh-cn'><meta http-equiv='Content-Type' content='text/html; charset=gb2312'><meta name='robots' content='none'></head>");

<%
lm=chkhtm(trim(request("lm")))
lm2=chkhtm(trim(request("lm2")))
if lm="" then lm=lm2
if lm2="" then lm2=lm
t=trim(request("t"))
hot=trim(request("hot"))
tj=chkhtm(trim(request("tj")))
news=trim(request("new"))
n=trim(request("n"))
more=trim(request("more"))
week=trim(request("week"))
line=trim(Request("line"))
pic=trim(Request("pic"))
zzly=trim(Request("zzly"))
hit=trim(Request("hit"))
pls=trim(Request("pls"))
lmname=trim(Request("lmname"))
font=trim(request("font"))
if font="" then font="9"
if line="" then line="2"
if n="" then n=30
n=int(n)
open=trim(request("open"))
if open="1" then
    open="_blank"
else
	open="_top"
end if
list=trim(request("list"))
if list="" then list=10
list=int(list)

icon=trim(request("icon"))
if icon="1" then 
icon="<font face=Wingdings>1</font>"
elseif icon<>"0" and icon<>"1" then 
icon="<img src="&icon&" border=0>"
else
  icon=""
end if

if (not isNumeric(lm2)) then
	lm2=0
end if

path=config("path")


sql = "select top "&list&" [id],[title],[titlecolor],[hit],[pic],[ontop],[time],[lm],[lm2],[lm3],[zz],[filename],[updat],[sh] from [news] where [title]<>'' and [sh]=1 "
if tj="1" then sql=sql&" and [tj]='推荐' "
if lm2<>"0" then
  sql=sql&" and (lm='"&lm2&"' or lm2='"&lm2&"' or lm3='"&lm2&"') "  
end if
if hot="1" then
 addtime=year(now())&"-"&month(now())&"-"&day(now())
 sql = sql&" and datediff('d',[time],now())<30 order by hit desc , updat desc , id desc"
else 
 sql= sql&" order by ontop desc , updat desc , id desc"
end if


Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1

%>
document.write("<table border=0 cellpadding=<%=line%> cellspacing=0 width=100%>");
<%
while not rs.eof

			   lm2=trim(rs("lm3"))
			    if lm2="0" or lm2="" then lm2=trim(rs("lm2"))
			      if lm2="0" or lm2="" then lm2=trim(rs("lm"))
			   if lm2="" then lm2=0
			   sql2 = "select * from lm where id="&clng(lm2)
			   Set rs2 = Server.CreateObject("ADODB.RecordSet")
			   rs2.Open sql2,conn,1,1
			   fontcolor=rs2("fontcolor")
			   pic=rs2("pic")
			   lmid=rs2("id")
			   lm=rs2("lm")&rs2("lm2")&rs2("lm3")
			   if rs("titlecolor")="默认颜色" then
			     fontcolor=rs2("fontcolor")
			   else
			     fontcolor=rs("titlecolor")
			   end if
			   
			   id=rs("id")
			   title=rs("title")
			   newshit=rs("hit")
			   title=replace(title,"""","")
			   
%>
document.write("<tr><td>");
<%
	if lmname="1" then 
%>
		document.write("<a href=<%=path%>news_more.asp?lm2=<%=lmid%> target=_blank><font style='font-size:<%=font%>pt'>[<%=lm%>]</font></a>&nbsp;");
<%
	end if
%>
document.write("<a href=<%=path%><%=hrefID(ID,rs("filename"))%> target=<%=open%> title='<%=title%>'><font color='<%=fontcolor%>' style='font-size:<%=font%>pt'><%=titleb(title,n)%></font></a>");
<% if trim(rs("pic"))<>"" and pic="1" then %>
 document.write("<font style='font-size:<%=font%>pt'>[图]</font>");
<%
end if
Newszz=rs("zz")
if zzly="1" then
%>
document.write("<font style='font-size:<%=font%>pt'>{<%=Newszz%>}</font>");
<%
end if
if hit="1" then
%>
document.write("<font style='font-size:<%=font%>pt'><a title='阅读数'>[<%=Newshit%>]</a></font>");
<%
end if
if pls="1" then

	set rspl = Server.CreateObject("ADODB.RecordSet")
	rspl.Open "select * from [NewsPL] where NewsID="&id&" order by id desc",conn,1,1
	NewsPLS=rspl.recordcount
	rspl.close:set rspl=nothing
%>
document.write("<font style='font-size:<%=font%>pt'><a title='评论数'>[<%=NewsPLS%>]</a></font>");
<%
end if
if news="1" then
	if datediff("d",rs("time"),date())<=newsx() then 
%>
document.write("</td><td align=left><img src=<%=path%>images/new.gif>");
<%
	end if
else
%>
	document.write("</td><td>");
<%	
end if
tttt=rs("time")
mmm=month(tttt)
if len(mmm)=1 then mmm="0"&mmm
ddd=day(tttt)
if len(ddd)=1 then ddd="0"&ddd
hhh=hour(tttt)
if len(hhh)=1 then hhh="0"&hhh
minu=Minute(tttt)
if len(minu)=1 then minu="0"&minu
%>
document.write("</td><td>");
<%
if t="1" then%>
document.write("<font color=333333 style='font-size:<%=font%>pt'><%=formatdatetime(tttt,1)%></font>");
<%elseif t="2" then %>
document.write("<font color=333333 style='font-size:<%=font%>pt'><%=formatdatetime(tttt,2)%></font>");
<%elseif t="3" then%>
document.write("<font color=333333 style='font-size:<%=font%>pt'>(<%=mmm%>月<%=ddd%>日)</font>");
<%elseif t="4" then%>
document.write("<font color=333333 style='font-size:<%=font%>pt'>[<%=mmm%>-<%=ddd%>]</font>");
<%elseif t="5" then%>
document.write("<font color=333333 style='font-size:<%=font%>pt'>(<%=mmm%>-<%=ddd%>&nbsp;<%=hhh%>:<%=minu%>)</font>");
<% end if %>
<%if week="1" then%>
document.write("<font color=333333 style='font-size:<%=font%>pt'>(<%=weekDayName(weekday(tttt))%>)</font>");
<%end if%>
document.write("</td></tr>");
<%
rs.movenext
wend

lm=trim(request("lm"))
lm2=trim(request("lm2"))
%>
document.write("</table>");
<%
if more="1" then
%>
document.write("<DIV align=right><a href=<%=path%>news_more.asp?lm=<%=lm%>&lm2=<%=lm2%>&open=<%=open%>&tj=<%=tj%>&hot=<%=hot%> target=<%=open%>><font style='font-size:<%=font%>pt'>更多内容</font></a></div>");
<%
else
end if
rs.close:set rs=nothing
conn.close:set conn=nothing
%>