<!--#include file = titleb.asp -->
<%
Sub Index_news_list(lm,lm2,t,hot,tj,news,n,more,week,line,pic,zzly,hit,pls,lmname,font,open,list,icon)
if lm=0 then lm=lm2
if lm2=0 then lm2=lm
if font=0 then font="9"
if line=0 then line="2"
if n=0 then n=30
n=int(n)
if open="1" then
    open="_blank"
else
	open="_top"
end if
if list=0 then list=10
list=int(list)


if icon="1" then 
icon="<img src='Images/news.gif' border=0>"
elseif icon="2" then 
icon="<img src='Images/buto.gif' border=0>"
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
<table border=0 cellpadding=<%=line%> cellspacing=0 width=100%>
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
<tr><td width=5 align=center><font style='font-size:<%=font%>pt'><%=icon%></font></td><td>
<%
	if lmname="1" then 
%>
		<a href=<%=path%>news_more.asp?lm2=<%=lmid%> target=_blank><font style='font-size:<%=font%>pt'>[<%=lm%>]</font></a>&nbsp;
<%
	end if
%>
<a href=<%=path%><%=hrefID(ID,rs("filename"))%> target=<%=open%> title='<%=title%>'><font color='<%=fontcolor%>' style='font-size:<%=font%>pt'><%=titleb(title,n)%></font></a>
<% if trim(rs("pic"))<>"" and pic="1" then %>
 <font style='font-size:<%=font%>pt'>[图]</font>
<%
end if
Newszz=rs("zz")
if zzly="1" then
%>
<font style='font-size:<%=font%>pt'>{<%=Newszz%>}</font>
<%
end if
if hit="1" then
%>
<font style='font-size:<%=font%>pt'><a title='阅读数'>[<%=Newshit%>]</a></font>
<%
end if
if pls="1" then

	set rspl = Server.CreateObject("ADODB.RecordSet")
	rspl.Open "select * from [NewsPL] where NewsID="&id&" order by id desc",conn,1,1
	NewsPLS=rspl.recordcount
	rspl.close:set rspl=nothing
%>
<font style='font-size:<%=font%>pt'><a title='评论数'>[<%=NewsPLS%>]</a></font>
<%
end if
if news="1" then
	if datediff("d",rs("time"),date())<=newsx() then 
%>
<img src=<%=path%>images/new.gif>
<%
	end if
else
%>
	</td><td>
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
</td><td>
<%
if t="1" then%>
<font color=gray style='font-size:<%=font%>pt'><%=formatdatetime(tttt,1)%></font>
<%elseif t="2" then %>
<font color=gray style='font-size:<%=font%>pt'>[<%=formatdatetime(tttt,2)%>]</font>
<%elseif t="3" then%>
<font color=333333 style='font-size:<%=font%>pt'>(<%=mmm%>月<%=ddd%>日)</font>
<%elseif t="4" then%>
<font color=333333 style='font-size:<%=font%>pt'>[<%=mmm%>-<%=ddd%>]</font>
<%elseif t="5" then%>
<font color=333333 style='font-size:<%=font%>pt'>(<%=mmm%>-<%=ddd%>&nbsp;<%=hhh%>:<%=minu%>)</font>
<% end if %>
<%if week="1" then%>
<font color=333333 style='font-size:<%=font%>pt'>(<%=weekDayName(weekday(tttt))%>)</font>
<%end if%>
</td></tr>
<%
rs.movenext
wend

lm=trim(request("lm"))
lm2=trim(request("lm2"))
%>
</table>
<%
if more="1" then
%>
<DIV align=right><a href=<%=path%>news_more.asp?lm=<%=lm%>&lm2=<%=lm2%>&open=<%=open%>&tj=<%=tj%>&hot=<%=hot%> target=<%=open%>><font style='font-size:<%=font%>pt'>更多内容</font></a></div>
<%
else
end if
rs.close:set rs=nothing
%>
<%
End Sub
%>

<%
Sub Index_pic_list(x,y,w,h,n,lm2,lm,open,font)
if lm2=0 then lm2=lm
if n=0 then n=20
n=int(n)
if font=0 then font=9
if open="1" then
  open="_blank"
else
  open="_top"
end if
if w=0 then w=100
if h=0 then h=100
if x=0 then x=1
if y=0 then y=1
x=int(x)
y=int(y)
xy=x*y
if (not isNumeric(lm2)) then
	lm2=0
end if

path=config("path")

sql = "select top "&xy&" * from news where ( pic like '%.jpg%' or pic like '%.JPG%' or pic like '%.gif%' or pic like '%.GIF%' ) and sh=1 "
if lm2<>"0" then sql=sql&" and (lm='"&lm2&"' or lm2='"&lm2&"' or lm3='"&lm2&"') "
sql=sql&" order by ontop desc , updat desc , id desc"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
%>
<table id='_ctl0_TopImage_Index_Class_15_TopImgList' cellspacing='0' Align='Center' border='0' style='width:100%;border-collapse:collapse;'>
<%
if rs.recordcount<>0 then
for yyyy=1 to y
%>
		<tr>
			<%
			if rs.eof then exit for
			for xxxx=1 to x
			if n<>0 then
			  ttt="<font color="&rs("titlecolor")&">"&titleb(rs("title"),n)&"</font>"
			end if
			id=rs("id")
			title=rs("title")
			pic=rs("pic")
			pic=replace(pic,"border=","bo=")
			Filename=rs("filename")
			if filename="" then filename=0
			%>
<td align=center style='font-size:<%=font%>pt;line-height:150%'><table width="110" border="0" cellpadding="0" cellspacing="0">
  <tr> 
    <td colspan="2" valign="top" rowspan="2"> 
      <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="000000">
        <tr> 
          <td width="110" height="110" bgcolor="333333" valign="middle" align="center"><a href=<%=path%><%=hrefID(ID,Filename)%> target='<%=open%>' title='<%=title%>'><img border=0 width=<%=w%> height=<%=h%> src=<%=pic%>></a>
		<div id="_ctl0_TopImage_Index_Class_18_TopImgList__ctl2_TitlePanel">
			
			<div align="center"><a id="_ctl0_TopImage_Index_Class_18_TopImgList__ctl2_Top_Links" title="<%=ttt%>" href="href=<%=path%><%=hrefID(ID,Filename)%> target='<%=open%>' title='<%=title%>'" target="_blank"><%=ttt%></a></div>
		
		</div></td>
        </tr>
      </table>
    </td>
    <td width="3" height="3" valign="top"></td>
  </tr>
  <tr> 
    <td height="104" bgcolor="000000"></td>
  </tr>
  <tr> 
    <td width="3" height="3" valign="top"></td>
    <td width="104" bgcolor="000000"></td>
    <td bgcolor="000000"></td>
  </tr>
</table></td>
			<%
			rs.movenext
			if rs.eof then exit for
			next
			%>
		</tr>
<%
next
else
%>
暂无图片信息
<%
end if
%>
	</table>

<%
rs.close
set rs=nothing
End Sub
%>