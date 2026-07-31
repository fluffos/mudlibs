<!--#include file = kuang5_conn.asp -->
<%
ON ERROR RESUME NEXT

Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [config]",conn,1,1
if rs.recordcount<>0 then
  sotop=rs("sotop")
  sobottom=rs("sobottom")
end if
rs.close
set rs=nothing
Response.Write sotop
%>
<head>
<!--#include file = language.asp -->
<!--#include file = titleb.asp -->
</head>

<style>
<!--
a:link       { font-size: 10.5pt; font-family: 宋体; color: #000000;text-decoration: none; }
a:visited    { color: #000000; font-family: 宋体; font-size: 10.5pt;text-decoration: none; }
a:hover      { font-size: 10.5pt; font-family: 宋体; color: #000000;TEXT-DECORATION: underline; }
body         { font-family: 宋体; color: #000000; font-size: 10.5pt }
p            { color: #000000; font-family: 宋体; font-size: 10.5pt }
td           { font-size: 10.5pt; font-family: 宋体; color: #000000 }
input        { font-size: 10.5pt; font-family: 宋体; color: #000000 }

-->
</style>
<BR><BR>
<table border=0 width=740 align=center><tr><td align=center>
<form method="post" action="so.asp">
<input type="text" name="word" size="25" value=<%=trim(request("word"))%>>
<select size="1" name="wh">
<option value="title">标题</option>
<option value="zz">作者</option>
</select>&nbsp;

<br>
<select size="1"  name="lm" style="font-size: 9pt">
<option value=" ">请选择栏目</option>
<option value=" ">所有栏目</option>
					  <%					  
					  sql = "select * from lm where lm<>'' order by id asc"
					  Set rs = Server.CreateObject("ADODB.RecordSet")
					  rs.Open sql,conn,1,1
					  while not rs.eof
					       %>
					         <option value='<%=rs("id")%>' <% if int(lmid)=rs("id") then response.write " selected" %>><%=rs("lm")%></option>
					       <%
							sql2 = "select * from lm where lmid='"&rs("id")&"' order by id asc"
							Set rs2 = Server.CreateObject("ADODB.RecordSet")
							rs2.Open sql2,conn,1,1
							while not rs2.eof
							%>
							   <option value='<%=rs2("id")%>' <% if int(lmid)=rs2("id") then response.write " selected" %>>　├<%=rs2("lm2")%></option>
							<%
				        Set rs33 = Server.CreateObject("ADODB.RecordSet")
				        rs33.Open "select * from [lm] where lmid='"&rs2("id")&"' and LM3<>'' order by id desc",conn,1,1
				        while not rs33.eof
				        %>
				        	<option value='<%=rs33("id")%>' <% if int(lmid)=rs33("id") then response.write " selected" %>>　　├<%=rs33("lm3")%></option>
				        <%
				        rs33.movenext
				        wend
							rs2.movenext
							wend
					  rs.movenext
					  wend 
					  rs.close
					  set rs=nothing
					 
					%>

</select>
<select size="1" name="year">
<option value="">年份</option>
<option value="">不限</option>
<option>2005</option>
<option>2006</option>
<option>2007</option>
<option>2008</option>
<option>2009</option>
<option>2010</option>
</select>　<select size="1" name="month">
<option value="">月份</option>
<option value="">不限</option>
<option>1</option>
<option>2</option>
<option>3</option>
<option>4</option>
<option>5</option>
<option>6</option>
<option>7</option>
<option>8</option>
<option>9</option>
<option>10</option>
<option>11</option>
<option>12</option>
</select><br>
　<input type="submit" value="搜索" name="kuang5">
</form>
</td></tr><tr><td>
<%

ON ERROR RESUME NEXT

word=chkhtm(trim(Request("word")))
lm=chkhtm(trim(request("lm")))
wh=chkhtm(trim(request("wh")))
yy=chkhtm(trim(request("year")))
mm=chkhtm(trim(request("month")))
if wh="" then wh="title"

nnn="<font color='#FF0000'><span style='background-color: #FFFF00'>"&word&"</span></font>"

sql = "select * from news where title<>'' and sh=1 "

if word<>"" then
	sql=sql&" and "&wh&" like '%"&word&"%' " 
	if yy<>"" then sql=sql&" and year(time)="&yy&" "
	if mm<>"" then sql=sql&" and month(time)="&mm&" "
	if lm<>"" then sql=sql&" and (lm='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"') "
	sql=sql&" order by id desc"
	

Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1

if rs.recordcount<>0 then 

page=int(request.QueryString ("page"))
rs.PageSize=10
pagecount=rs.pagesize
if page<=0 then page=1
if request.QueryString("page")="" then page=1
rs.AbsolutePage=page
%>
<%
    for i=1 to pagecount
    	 
    	 lmid=rs("lm3")
    	 if lmid="0" then lmid=rs("lm2")
    	 if lmid="0" then lmid=rs("lm")
         sql2 = "select * from lm where id="&lmid
         Set rs2 = Server.CreateObject("ADODB.RecordSet")
         rs2.Open sql2,conn,1,1
         lm=rs2("lm")&rs2("lm2")&rs2("lm3")
         title=replace(rs("title"),word,nnn)
         
         nr=glhtml(rs("content"))
         'nr=replace(nr,"<","＜")
         'nr=replace(nr,">","＞")
         nr=titleb(nr,200)
         nr=replace(nr,word,nnn)
         content="　　"&nr
         
        
    %>
      <font face=Wingdings>1</font>&nbsp;[<%=lm%>]&nbsp;<a href="news_view.asp?newsid=<%=rs("id")%>" target=_top><font color="<%=rs("titlecolor")%>"><%=title%></font></a><font color=999999>(<%=formatdatetime(rs("time"),1)%>)</font><BR>
      <font color=999999>
      <%
         if len(content)<250 then
           Response.Write content
         Else
           Response.Write content
         end if
      %></font><br><br>
    <%
    rs.movenext
    if rs.eof then exit for
    next
else
  response.write "<center><BR><BR><BR>无记录<BR><BR><BR><BR>"
end if
%>
</td></tr></table>
<BR><BR><center>
<%
if rs.recordcount<>0 then
lm=trim(request("lm"))
  if page>1 then%>
     <a href='<%=request.servervariables("URL")%>?page=1&word=<%=word%>&id=<%=trim(request("id"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&wh=<%=wh%>&yy=<%=yy%>&mm=<%=mm%>&lm=<%=lm%>'>首页</a>
     <a href='<%=request.servervariables("URL")%>?page=<%=page-1%>&word=<%=word%>&id=<%=trim(request("id"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&wh=<%=wh%>&yy=<%=yy%>&mm=<%=mm%>&lm=<%=lm%>'>上一页</a>
  <%end if%>
  <%if page<rs.pagecount then%>
     <a href='<%=request.servervariables("URL")%>?page=<%=page+1%>&word=<%=word%>&id=<%=trim(request("id"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&wh=<%=wh%>&yy=<%=yy%>&mm=<%=mm%>&lm=<%=lm%>'>下一页</a>
     <a href='<%=request.servervariables("URL")%>?page=<%=rs.pagecount%>&word=<%=word%>&id=<%=trim(request("id"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&wh=<%=wh%>&yy=<%=yy%>&mm=<%=mm%>&lm=<%=lm%>'>尾页</a>
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
          <option value="<%=request.servervariables("URL")%>?page=<%=i%>&word=<%=word%>&id=<%=trim(request("id"))%>&lmname=<%=trim(request("lmname"))%>&open=<%=trim(request("open"))%>&n=<%=trim(request("n"))%>&wh=<%=wh%>&yy=<%=yy%>&mm=<%=mm%>&lm=<%=lm%>" <%if page=i then response.write "selected"%>>第<%=i%>页</option>
        <%next%>
    </select>
</p>
<%end if

end if

Response.Write sobottom

conn.close
set conn=nothing
%>