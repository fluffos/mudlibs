<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
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

 Response.Clear
 Response.CharSet="gb2312"  '数据集
 Response.ContentType="text/xml"  '数据流格式定义
 Response.Write "<?xml version=""1.0"" encoding=""gb2312""?>"&vbNewLine

lm=chkhtm(trim(request("lm")))
if (not isNumeric(lm)) then
	lm=0
end if
if lm="" then lm=0
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [lm] where id="&lm&" order by id desc",conn,1,1 
if rs.recordcount<>0 then
	lmname=rs("lm")&rs("lm2")&rs("lm3")
else
	lmname="所有栏目"	
end if
rs.close:set rs=nothing
  sRssHead = "<rss version='2.0'>" & vbNewLine 
  sRssHead = sRssHead & "<channel>" & vbNewLine 
  sRssHead = sRssHead & "<title>"&lmname&"</title>" & vbNewLine 
  sRssHead = sRssHead & "<description>"&now()&"</description>" & vbNewLine 
  sRssHead = sRssHead & "<link>http://"&Request.ServerVariables("SERVER_NAME")&"</link>" & vbNewLine 
  sRssHead = sRssHead & "<language>zh-cn</language>" & vbNewLine 
  sRssHead = sRssHead & "<docs>文章更新</docs>" & vbNewLine 
  sRssHead = sRssHead & "<generator>Rss Generator By "&Request.ServerVariables("SERVER_NAME")&"</generator>" & vbNewLine 

  sRssEnd = "</channel></rss>" 

  response.write sRssHead
  
lm=trim(Request("lm"))
if lm="" then lm=0

if (not isNumeric(lm)) then
	lm=0
end if

path=config("path")

SQL="select top 20 * from [News] where title<>'' "
if lm<>0 then sql=sql&" and ( lm='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"' ) "
sql=sql&" order by id desc"
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open SQL,conn,1,1
  while not rs.eof
  
  lm=rs("lm2")
  if lm="0" then lm=rs("lm")
  set rs2 = Server.CreateObject("ADODB.RecordSet")
  rs2.Open "select * from [lm] where id="&lm&" order by id desc",conn,1,1
  if rs2.recordcount<>0 then
     lmname=rs2("lm")&rs2("lm2")&rs2("lm3")
     lmid=rs2("id")
  end if
  rs2.close:set rs2=nothing
  content=glhtml(rs("content"))
  title=glhtml(rs("title"))
  content=replace(content,"""","")
  content=replace(content,"'","")
  id=rs("id")
  Response.Write "<item><title>"&title&"</title><link>http://"&Request.ServerVariables("SERVER_NAME")&""&path&hrefID(ID,rs("filename"))&"</link><author>"&lmname&"</author><pubDate>"&rs("time")&"</pubDate>"
  Response.Write "<description><![CDATA["&titleb(content,300)&"]]></description>"
  Response.Write "</item>"
  rs.movenext
  wend
  rs.close
  set rs=nothing

  response.write sRssend
  
  conn.close:set conn=nothing
  %>

