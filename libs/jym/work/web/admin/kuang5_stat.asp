<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<head>
<!--#include file = language.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
</head>
<body>
<%



Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select id,hit from [news]",conn,1,1
wzsl=rs.recordcount
hit=0
while not rs.eof
  hit=hit+rs("hit")
rs.movenext
wend
rs.close
set rs=nothing
%>
	<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th colspan="2">目前文章总数：<%=wzsl%>，总共阅读<%=hit%>次。其中包括如下：</th>
		</tr>
		<tr>
			<td class=tablerow align="center" colspan="2">
<table border="1" width="500" id="table2" cellpadding="3" style="border-collapse: collapse" cellspacing="0" bordercolor="#CCCCCC">
<%
lll="<img src=images/001.gif border=0 height=20 width=17>"

sql = "select * from lm where lm<>'' order by id asc"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1

if rs.recordcount<>0 then
 for i=0 to rs.recordcount
%>
	<tr>
		<td class=tablerow width="241" bgcolor="#F3F3F3">
		<%
		  response.write "<B><font color="&rs("fontcolor")&">"&rs("lm")&"</font></b>"

		%></td>
		<td class=tablerow width="118" bgcolor="#F3F3F3">
		<%
           sql2 = "select id,lm,lm2,lm3,hit from news where lm='"&rs("id")&"'"
           Set rs2 = Server.CreateObject("ADODB.RecordSet")
           rs2.Open sql2,conn,1,1
           response.write "文章："&rs2.recordcount
           hit=0
           while not rs2.eof
             hit=hit+rs2("hit")
           rs2.movenext
           wend
		%>
		</td>
		<td class=tablerow width="119" bgcolor="#F3F3F3">
		总阅读：<%=hit%></td>
	</tr>
  <%
    sql3 = "select * from lm where lmid='"&rs("ID")&"' order by id asc"
    Set rs3 = Server.CreateObject("ADODB.RecordSet")
    rs3.Open sql3,conn,1,1
    while not rs3.eof
  %>	
	<tr>
		<td class=tablerow width="241">　　├ <a href=kuang5_news_list.asp?lm=<%=rs3("id")%>><font color=<%=rs3("fontcolor")%>><%=rs3("lm2")%></font></a></td>
		<td class=tablerow width="118">
		  <%
		    sql4 = "select id,lm,lm2,lm3,hit from news where lm2='"&rs3("id")&"' order by id desc"
		    Set rs4 = Server.CreateObject("ADODB.RecordSet")
		    rs4.Open sql4,conn,1,1
		    response.write "文章："&rs4.recordcount
		    hit4=0
           while not rs4.eof
             hit4=hit4+rs4("hit")
           rs4.movenext
           wend
		  
		  %>
		</td>
		<td class=tablerow width="119">
		阅读：<%=hit4%></td>
	</tr>
<%
Set rs33 = Server.CreateObject("ADODB.RecordSet")
rs33.Open "select * from [lm] where lmid='"&rs3("id")&"' and lm3<>'' order by id asc",conn,1,1
while not rs33.eof
%>
	<tr>
		<td class=tablerow width="241">　　　　├ <%=rs33("lm3")%></td>
		<td class=tablerow width="118">
		   <%
		     Set rs331 = Server.CreateObject("ADODB.RecordSet")
		     rs331.Open "select id,lm3,hit from [news] where lm3='"&rs33("id")&"' order by id desc",conn,1,1
		     Response.Write "　文章："&rs331.recordcount
		   %>
		</td>
		<td class=tablerow width="119">　阅读：
		<%
		hit=0
		while not rs331.eof
		  hit=rs331("hit")+hit
		rs331.movenext
		wend
		rs331.close
		set rs331=nothing
		Response.Write hit
		%>
		</td>
	</tr>	
<%
rs33.movenext
wend

rs3.movenext
wend


  rs.movenext
  if rs.eof then exit for
 next
end if
%>	

</table>
			</td>
		</tr>
<%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [admin]",conn,1,1
%>
		<tr>
			<td class=tablerow background="images/topBar_bg.gif" colspan="2">目前系统用户有<%=rs.recordcount%>个，其中包括如下：
			　　　　　(<a href="kuang5_stat_user.asp">查看用户文章排名</a>)</td>
		</tr>
		<tr>
			<td class=tablerow colspan="2">
			<div align="center">
				<table border="1" cellpadding="3" cellspacing="0" width="500" id="table3" style="border-collapse: collapse" bordercolor="#C0C0C0">
				<%
				while not rs.eof
				%>
					<tr>
						<td class=tablerow width="249"><%=rs("user")%></td>
						<td class=tablerow width="249">
						<%
						Set rs2 = Server.CreateObject("ADODB.RecordSet")
						rs2.Open "select adduser,id from [news] where adduser='"&rs("user")&"' order by id desc",conn,1,1
						Response.Write "共有"&rs2.recordcount&"篇文章，"
						rs2.close:set rs2=nothing
						
						set rs2 = Server.CreateObject("ADODB.RecordSet")
						rs2.Open "select adduser,id,sh from [News] where adduser='"&rs("user")&"' and sh=2 order by id desc",conn,1,1
						Response.Write "有"&rs2.recordcount&"篇未审核"
						rs2.close:set rs2=nothing
						%>
						</td>
					</tr>
				<%
				rs.movenext
				wend
				rs.close
				set rs=nothing
				%>
				</table>
			</div>
			</td>
		</tr>
		<tr>
			<td class=tablerow background="images/topBar_bg.gif" colspan="2">
			文章来源统计：</td>
		</tr>
		<tr>
			<td class=tablerow colspan="2">
			<div align="center">
				<table border="1" cellpadding="3" width="500" id="table4" style="border-collapse: collapse" bordercolor="#C0C0C0">
				<%

sql = "select distinct adduser from news"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
while not rs.eof
				%>
					<tr>
						<td class=tablerow width="249"><%=rs("adduser")%></td>
						<td class=tablerow width="249">
						<%
						Set rs2 = Server.CreateObject("ADODB.RecordSet")
						rs2.Open "select adduser,id from [news] where adduser='"&rs("adduser")&"' order by id desc",conn,1,1
						Response.Write "共有"&rs2.recordcount&"篇文章"
						%>
						</td>
					</tr>
<%
rs.movenext
wend
rs.close
set rs=nothing
%>
				</table>
			</div>
			</td>
		</tr>
			</table>
<table border=0><tr><td height=3></td></tr></table>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th width="349" align="center">
			文章阅读前十名</td>
			<th width="349" align="center">
			文章阅读后十名</td>
		</tr>
		<tr>
			<td class=tablerow width="349">
<%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select top 10 * from [news]  order by hit desc , id desc",conn,1,1
while not rs.eof
  Response.Write "　·<a href=../news_view.asp?newsid="&rs("id")&" target=_blank><font color=999999>"&titleb(rs("title"),30)&"</font></a><font color=999999>("&rs("hit")&"次)</font><BR>"
rs.movenext
wend
%>
			</td>
			<td class=tablerow width="349">
<%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select top 10 * from [news] order by hit asc , id desc",conn,1,1
while not rs.eof
  Response.Write "　·<a href=../news_view.asp?newsid="&rs("id")&" target=_blank><font color=999999>"&titleb(rs("title"),30)&"</font></a><font color=999999>("&rs("hit")&"次)</font><BR>"
rs.movenext
wend
%></td>
		</tr>
		<tr>
			<td class=tablerow colspan="2" background="images/topBar_bg.gif">
			评论情况：</td>
		</tr>
		<tr>
			<td class=tablerow colspan="2"><font color="#999999">共评论数量：
			<%
			Set rs = Server.CreateObject("ADODB.RecordSet")
			rs.Open "select id from [newspl] order by id desc",conn,1,1
			Response.Write rs.recordcount
			%>
			</font>
			</td>
		</tr>
		</table>
<center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
</table></center>
<%
conn.close
set conn=nothing
%>