
<%
Sub Index_pic_list(x,y,w,h,n,lm2,lm,open,font)
x=trim(request("x"))
y=trim(request("y"))
w=trim(request("w"))
h=trim(request("h"))
n=trim(request("n"))
lm2=trim(request("lm2"))
if lm2="" then lm2=trim(request("lm"))
if n="" then n=20
n=int(n)
open=trim(request("open"))
font=trim(request("font"))
if font="" then font=9
if open="1" then
  open="_blank"
else
  open="_top"
end if
if w="" then w=100
if h="" then h=100
if x="" then x=1
if y="" then y=1
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
response.write "<table id='_ctl0_TopImage_Index_Class_15_TopImgList' cellspacing='0' Align='Center' border='0' style='width:100%;border-collapse:collapse;'>"
<%
if rs.recordcount<>0 then
for yyyy=1 to y
%>
		response.write "<tr>"
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
			response.write "<td align='Center'>"
		response.write "<table width='165' border='0' cellpadding='0' cellspacing='0'>"
  response.write "<tr>" 
    response.write "<td colspan='2' valign='top' rowspan='2'>" 
      response.write "<table width='100%' border='0' cellpadding='0' cellspacing='1' bgcolor='333333'>"
      response.write "<tr>" 
      response.write "<td width='165' height='135' bgcolor='cdcdcd' valign='middle' align='center'><a href=<%=path%><%=hrefID(ID,Filename)%>><Script Language='JavaScript'>ShowPreviewImg('<%=pic%>',150,110,'True');</Script></a>"
      response.write "<div id='_ctl0_TopImage_Index_Class_15_TopImgList__ctl0_TitlePanel'>"
			
      response.write "<div align='center'><a href=<%=path%><%=hrefID(ID,Filename)%> target='<%=open%>' title='<%=title%>'><%=ttt%></a></div>"
		
      response.write "</div></td>"
      response.write "</tr>"
      response.write "</table>"
      response.write "</td>"
      response.write "<td width='4' height='4' valign='top'></td>"
      response.write "</tr>"
      response.write "<tr>" 
      response.write "<td height='131' bgcolor='333333'></td>"
      response.write "</tr>"
      response.write "<tr>"
      response.write "<td width='4' height='4' valign='top'></td>"
      response.write "<td width='161' bgcolor='333333'></td>"
      response.write "<td bgcolor='333333'></td>"
      response.write "</tr>"
      response.write "</table>"
      response.write "</td>"
			<%
			rs.movenext
			if rs.eof then exit for
			next
			%>
		response.write "</tr>"
<%
next
else
%>
response.write "暂无图片信息"
<%
end if
%>
	response.write "</table>"


<%
conn.close:set conn=nothing
%>