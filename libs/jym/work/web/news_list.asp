<%
function titleb(str,strlen)
	dim l,t,c, i
	l=len(str)
	t=0
	for i=1 to l
	c=Abs(Asc(Mid(str,i,1)))
	if c>255 then
	t=t+2
	else
	t=t+1
	end if
	if t>=strlen then
	titleb=left(str,i)&"…"
	exit for
	else
	titleb=str&""
	end if
	next
end function

function newslist(ll,tt,lmnameid,openwindow,icon)

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select moreline from [config] ",conn,1,1
if rs.recordcount<>0 then
	moreline=rs("moreline")
end if
rs.close
set rs=nothing

lmid=trim(request("lm"))
lm2=trim(request("lm2"))
if lm="" then lm=lm2
if lm2="" then lm2=lm
n=trim(request("n"))
list=trim(request("list"))
hot=trim(request("hot"))
tj=trim(request("tj"))
more=trim(request("more"))
'if lmname="" then lmname=0
if n="" then n=20
if list="" then list=10
if more="" then more=1
if openwindow="1" then
   openwindow=" target=_blank "
else
   openwindow=" target=_top  "
end if
%>
<!--#include file = kuang5_conn.asp -->

<%
lm=trim(request("lm"))
lm2=trim(request("lm2"))

if lm="" then lm=lm2
if lm2="" then lm2=lm

if (not isNumeric(lm)) then
	lm=0
end if

word=trim(request("word"))

sql= "select * from news where title<>'' and sh=1 "

if lm2<>"0" then
  sql=sql&" and (lm='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"') "  
end if

if tj="1" then
   sql= sql & " and tj='推荐' "
end if
if hot="1" then
  sql=sql & " order by hit desc , updat desc  , id desc"
else
  sql=sql & " order by ontop desc , updat desc , id desc"
end if
%>
<div align="center">
	<table border="0" cellpadding="3" cellspacing="0" width="100%">
		
<%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
if rs.recordcount<>0 then 

page=int(request.QueryString ("page"))
rs.PageSize=ll
pagecount=rs.pagesize
if page<=0 then page=1
if request.QueryString("page")="" then page=1
rs.AbsolutePage=page

    for i=1 to pagecount
    
    %>
    <tr>
			<td align=center style='line-height:<%=moreline%>pt'>
    <%
    lm2=rs("lm3")
     if lm2="0" or lm2="" then lm2=rs("lm2")
        if lm2="0" or lm2="" then lm2=rs("lm")
         sql2 = "select * from lm where id="&lm2
         Set rs2 = Server.CreateObject("ADODB.RecordSet")
         rs2.Open sql2,conn,1,1
         lm=rs2("lm")&rs2("lm2")&rs2("lm3")
         pic=rs2("pic")
         
			   if rs("titlecolor")="默认颜色" or rs("titlecolor")="" then
			     fontcolor=rs2("fontcolor")
			   else
			     fontcolor=rs("titlecolor")
			   end if

    %>
      <td width="4%" height="25" align="center"><img src="/Images/space1.gif" width="11" height="12"></td><td align=left style='line-height:<%=moreline%>pt'><%if lmnameid="1" then response.write "[<a href=news_more.asp?lm2="&rs2("id")&">"&lm&"</a>]&nbsp;"%><a href="<%=hrefID(rs("ID"),rs("filename"))%>" <%=openwindow%>><font color="<%=trim(fontcolor)%>"><%=titleb(rs("title"),tt)%></font></a>
      <font color=999999>
      <%
		if newshit="1" then response.write "阅读:"&rs("hit")
        if trim(rs("pic"))<>"" and pic="1" then Response.Write "[图]"
      %>
      </td><td>
      <%
        if newstime="1" then response.write "("&formatdatetime(rs("time"),1)&")"
      %>
      
      </td></tr>
	  						<tr>
							<td height="1" colspan="4" background="/Images/space2.gif"></td>
						</tr>
    <%
    rs.movenext
    if rs.eof then exit for
    next
else
  response.write "<center><BR><BR><BR>无记录<BR><BR><BR><BR>"
end if
%>
</table><BR>
<table><tr><td>
<%
if rs.recordcount<>0 then
  if page>1 then%>
     <a href='<%=request.servervariables("URL")%>?page=1&word=<%=word%>&lm=<%=trim(request("lm"))%>&lm2=<%=trim(request("lm2"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&hot=<%=trim(request("hot"))%>&tj=<%=trim(request("tj"))%>'>首页</a>
     <a href='<%=request.servervariables("URL")%>?page=<%=page-1%>&word=<%=word%>&lm=<%=trim(request("lm"))%>&lm2=<%=trim(request("lm2"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&hot=<%=trim(request("hot"))%>&tj=<%=trim(request("tj"))%>'>上一页</a>
  <%end if%>
  <%if page<rs.pagecount then%>
     <a href='<%=request.servervariables("URL")%>?page=<%=page+1%>&word=<%=word%>&lm=<%=trim(request("lm"))%>&lm2=<%=trim(request("lm2"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&hot=<%=trim(request("hot"))%>&tj=<%=trim(request("tj"))%>'>下一页</a>
     <a href='<%=request.servervariables("URL")%>?page=<%=rs.pagecount%>&word=<%=word%>&lm=<%=trim(request("lm"))%>&lm2=<%=trim(request("lm2"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&hot=<%=trim(request("hot"))%>&tj=<%=trim(request("tj"))%>'>尾页</a>
  <%end if%>
　共<%=rs.recordcount%>条　每页显示<%=pagecount%>条　　第<%=page%>页　共<%=rs.pagecount%>页				
    <script language="JavaScript">
      <!--
       function FP_jumpMenu(el,frm,sel) {//v1.0
       var href=el.options[el.selectedIndex].value; if(sel) el.selectedIndex=0;
       if('_new'==frm) open(href); else eval(frm+".location='"+href+"'");
        }
       // -->
     </script>

   <select size="1" onchange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="font-size: 9pt; border-style: solid; border-width: 1px">
        <%for i=1 to rs.pagecount%>
          <option value="<%=request.servervariables("URL")%>?page=<%=i%>&word=<%=word%>&lm=<%=trim(request("lm"))%>&lm2=<%=trim(request("lm2"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&hot=<%=trim(request("hot"))%>&tj=<%=trim(request("tj"))%>" <%if page=i then response.write "selected"%>>第<%=i%>页</option>
        <%next%>
    </select></td></tr></table>
</p>
<%end if%><%
end function
%>