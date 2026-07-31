<% Response.Buffer = True %>
<!--#include file="kuang5_h.asp"-->
<!--#include file="head.asp"-->
<!--#include file = language.asp -->
<!--#include file = titleb.asp -->

<%

newsid=chkhtm(trim(Request("newsid")))
page=chkhtm(trim(request("page")))
if newsid="" then newsid=chkhtm(trim(Request("id")))
id=newsid
if newsid="" then 
  Response.Write "<BR><BR><BR><center>参数不正确</center>"
  response.end  
end if

if (not isNumeric(newsid)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数，请勿随意提交数据！');location.href='/';</Script>"
  response.end  
end if

if (not isNumeric(page)) then
	page=""
end if

sql = "select * from news where id="&newsid
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
if rs.recordcount=0 then
  Response.Write "<BR><BR><Center>该文章已经没有了，可能已经删除了！<BR><BR>"
  rs.close:set rs=nothing
  conn.close:set conn=nothing
  Response.end
end if
title=rs("title")
title="<font color="&rs("titlecolor")&">"&trim(title)&"</font>"
webtitle=rs("title")
htitle=trim(rs("htitle"))
if htitle="" then htitle="&nbsp;"
dat=rs("time")
zz=trim(rs("zz"))
laiyuan=rs("laiyuan")
piczz=rs("piczz")
hit=rs("hit")+1
hit=hit
webxgnews=chkhtm(trim(rs("xgnews")))
if webxgnews="" then webxgnews=left(rs("title"),3)
if webxgnews<>"" then
	webxgnews=replace(webxgnews,"[","")
	webxgnews=replace(webxgnews,"]","")
end if

SQL="select top 10 [id],[title],[xgnews] from [news] where ( [title] like '%"&webxgnews&"%' or [xgnews] like '%"&webxgnews&"%' ) and [id]<>"&chkhtm(trim(Request("newsid")))&" order by [id] desc"
Set xgrs = Server.CreateObject("ADODB.RecordSet")
xgrs.Open SQL,conn,1,1
while not xgrs.eof
   xgnews=xgnews + "·<a href=news_view.asp?newsid="&xgrs("id")&" title='"&xgrs("title")&"'>"&xgrs("title")&"</a><BR>"
xgrs.movenext
wend
if xgrs.recordcount=0 then xgnews="没有相关信息"
xgrs.close
set xgrs=nothing

content=rs("content")
content=replace(content,"]","］")
content=replace(content,"[","［")


if instr(content,"$$分页$$")<>0 then
	if page="" then page=1
	nrfy=split(content,"$$分页$$")
	page=page-1
	if page>ubound(nrfy) then page=0
	if page<0 then page=0
	content=nrfy(page)
	fy=1
	
	content=content&"<center>第&nbsp;"
	for i=0 to ubound(nrfy)
		sss=""
		if clng(page)=clng(i) then
			sss="font-weight:700;background-color: #EEEEEE;"
		end if
		content=content&"<a href=?NewsID="&NewsID&"&page="&i+1&" style='"&sss&"'>&nbsp;"&i+1&"&nbsp;</a>"
	next
	content=content&"页</center>"
end if
 
  

  
  
if pl()=1 then ppll="<BR><script language='javascript' src='js_news_pl.asp?id="&id&"'></script>"
url=trim(rs("url"))

conn.Execute = "update news set hit=hit+1 where ID="&newsid

if url<>"" then 
  Response.Redirect url
end if

pp=""
pp=pp&"&nbsp;"
pp=pp&"<a name=pl><img src=images/bbstitle.gif></a><a href=#pl onclick='window.open(""NewsPL.asp?id="&rs("id")&""",""newsview"",""width=680,height=400,top=70,left=150,scrollbars=yes"" )'  title='"&rs("title")&"'>发表,查看评论</a>&nbsp;"
pp=pp&"<img border='0' src='images/print.gif' width='16' height='16'><a href='javascript:window.print()'>打印本页</a>&nbsp;"
pp=pp&"<img border='0' src='images/soso.gif'><a href=soso.asp?word="&webxgnews&" target=_blank>搜索相关信息</a>"

response.flush
%>

<%



    lmid=rs("lm3")
     if lmid="0" or lmid="" then lmid=rs("lm2")
        if lmid="0" or lmid="" then lmid=rs("lm")
sql2 = "select * from lm where mb<>'' and  id="&clng(lmid)
Set rs2 = Server.CreateObject("ADODB.RecordSet")
rs2.Open sql2,conn,1,1

if rs2.recordcount<>0 then

lm=rs2("lm")&rs2("lm2")&rs2("lm3")

mbid=rs2("mb")

if laiyuan="" then laiyuan="&nbsp;"
if piczz="" then piczz=" "
if zz="" then zz=" "
sql3 = "select * from xymb where id="&mbid
Set rs3 = Server.CreateObject("ADODB.RecordSet")
rs3.Open sql3,conn,1,1
if htitle="" then htitle="&nbsp;"
if rs3.recordcount<>0 then
  updown=rs3("updown")
  nr=rs3("mid")
  nr=replace(nr,"$$kefu$$",kefu)	
  nr=replace(nr,"$$Path$$",lmpath())
  nr=replace(nr,"$$Subheading$$",htitle)
  nr=replace(nr,"$$title$$",title)
  nr=replace(nr,"$$Columns$$",lm)
  nr=replace(nr,"$$Time$$",dat)
  nr=replace(nr,"$$Visited$$",hit)
  nr=replace(nr,"$$Content$$",content)
  nr=replace(nr,"$$Source$$",laiyuan)
  nr=replace(nr,"$$Author$$",zz)
  nr=replace(nr,"$$Photoby$$",piczz)
  nr=replace(nr,"$$Comments$$",ppll)
  nr=replace(nr,"$$打印$$",pp)
  nr=replace(nr,"$$Toolbar$$",pp)
  nr=replace(nr,"$$Related$$",xgnews)
  nr=replace(nr,"$$NEWSID$$",newsid)

  if updown=0 then
    nr=replace(nr,"$$toptobottom$$","")
  else
    Set rs4 = Server.CreateObject("ADODB.RecordSet")
    rs4.Open "select top 1 * from [news] where (lm2='"&lmid&"' or lm='"&lmid&"' or lm3='"&lmid&"') and id<"&newsid&" and sh=1 order by id desc",conn,1,1
    if rs4.recordcount<>0 then
	    uuu="<a style='color:#FFCC00;' href="&hrefID(rs4("id"),rs4("filename"))&">上一条</a>&nbsp;<font color=#FFCC00>/</font>&nbsp;"
	else
	    uuu="<font color=#FFCC00>上一条：已经没有了</font><BR>"
	end if
    Set rs5 = Server.CreateObject("ADODB.RecordSet")
    rs5.Open "select top 1 * from [news] where (lm2='"&lmid&"' or lm='"&lmid&"' or lm3='"&lmid&"') and id>"&newsid&" and sh=1 order by id asc",conn,1,1
    if rs5.recordcount<>0 then
	    uuu=uuu&"<a style='color:#FFCC00;' href="&hrefID(rs5("id"),rs5("filename"))&">下一条</a>"
	else
	    uuu=uuu&"<font color=#FFCC00>下一条：已经没有了</font>"
	end if
    nr=replace(nr,"$$toptobottom$$",uuu)
    rs4.close
    set rs4=nothing
    rs5.close
    set rs5=nothing
  end if
  response.write nr
response.flush
else
  response.write "<center><BR><BR><BR>设置不正确。"
end if 
rs3.close
set rs3=nothing
else
  Response.Write "<center><BR><BR><BR>此栏目设置不正确"
  mbid=1
end if

'rs.close
'set rs=nothing
rs2.close
set rs2=nothing
%>
<!--#include file="foot.asp"-->
<%
conn.close
set conn=nothing
%>
