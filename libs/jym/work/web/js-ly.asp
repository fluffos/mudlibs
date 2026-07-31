<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<%

function chkhtm(stra)
  stra=replace(stra,"<","&lt;")
  stra=replace(stra,">","&gt;")
  stra=replace(stra,"'","")
  stra=replace(stra,"(","（")
  stra=replace(stra,")","）")
  stra=replace(stra,";","；")
  stra=replace(stra,",","，")
  stra=replace(stra,"%","％")
  stra=replace(stra,"+","＋")
  chkhtm=stra
end function

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

path=config("path")

Response.flush 
list=chkhtm(trim(request("list")))
font=chkhtm(trim(request("font")))
color=chkhtm(trim(request("color")))
n=chkhtm(trim(request("n")))
lb=chkhtm(trim(request("lb")))
if list="" then list=10
list=int(list)
if font="" then font="9"
if color="" then color="000000"
if lb="" then lb=0
if n="" then n="30"
n=int(n)
lb=int(lb)

sql="select top "&list&" * from [ly] where bm='0' and sh=1 "
if lb<>0 then sql=sql&" and lb="&lb&" "
sql=sql&" order by id desc"
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
while not rs.eof
   id=rs("id")
   title=titleb(rs("title"),n)
%>
	document.write("<a href=<%=path%>lyview.asp?id=<%=id%> target=_blank style='font-size:<%=font%>pt;color=<%=color%>'><li><%=title%></li></font></a>");
<%
Response.flush  
rs.movenext
wend
rs.close
set rs=nothing
conn.close
set conn=nothing
%>
<%
'=================================
'   狂舞游戏网站管理系统
'   www.kuang5.com
'  copyright(c)2007-2009 狂舞网络
'=================================
%>