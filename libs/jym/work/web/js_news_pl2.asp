<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<%
id=chkhtm(trim(request("id")))

sql = "select top 5 * from newspl where sh=1 and newsid="&clng(id)
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1

%>

document.write("<table border='1' cellpadding='2' width='100%' id='table1' style='border-collapse: collapse' bordercolor='#C0C0C0'>");
document.write("<tr><td align=center background=../../../images/bj3.jpg height=25><font style='font-size:9pt'>相关网友评论</font>　　　　<a href=../../../newspl.asp?id=<%=id%> target=_blank><font style='font-size:9pt'>发表/查看所有评论</font></a><div align='center'></td></tr>");
<%
b=0
while not rs.eof
username=rs("username")
addtime=rs("addtime")
content=rs("content")
content=replace(content,"""","'")
content=replace(content,chr(10),"")
content=replace(content,chr(13),"<BR>")
if b=1 then
	bbb="style='background-color: #F8F3F3'"
	b=0
else
	b=b+1
	bbb=""
end if
%>
document.write("<tr <%=bbb%>>");
document.write("<td style='font-size:9pt;word-break:break-all'>　<font color=66666><%=username%>　<%=addtime%>　评论说：</font><br><img border=0 src=../../../images/bbstitle.gif width=16 height=15>　<%=content%></td>");
document.write("</tr>");
<%
rs.movenext
wend
if rs.recordcount=0 then
	Response.Write "document.write(""<tr><td>暂时无评论</td></tr>"");"
end if
rs.close
set rs=nothing
%>
document.write("</table></div>");

<%
if config("plfb")="1" then
%>
	document.write("<form method='POST' action='../../../NewsPL_save.asp?id=<%=id%>&action=js' onsubmit='return FrontPage_Form1_Validator(this)' language='JavaScript' name='FrontPage_Form1231'>");
	document.write("<div align='center'><table border='1' cellpadding='5' width='100%' id='table1' style='border-collapse: collapse' bordercolor='#C0C0C0' bgcolor='#F5F5F5'><tr>");
	document.write("<td  align='center'>姓名</td><td>");
	document.write("<input type='text' name='username' size='20' style='background-color: #F5F5F5' maxlength='8'></td>");
	document.write("</tr><tr><td align='center' bgcolor='#FFFFFF'>评论</td><td bgcolor='#FFFFFF'>");
	document.write("<textarea rows='4' name='content' cols='60'></textarea></td>");
	document.write("</tr></table></div>");
	document.write("<div align='center'><input type='submit' value='提交' name='B1'>&nbsp;&nbsp;&nbsp; <input type='reset' value='重置' name='B2'></div></form>");
<%
end if

conn.close
set conn=nothing

%>