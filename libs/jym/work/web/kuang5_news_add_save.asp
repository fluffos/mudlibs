<%@ Language=VBScript codepage=936%>
<!--#include file = kuang5_chk.asp -->
<%
'session.codepage=936
Randomize
dtt= int((999-100+1) * RND +100)
%>
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<meta http-equiv="Content-Language" content="zh-cn">
<!--#include file = language.asp -->
<STYLE type="text/css">
<!--
a:link       {text-decoration: none; font-family: AdobeSm; color: #000000 }
a:visited    {text-decoration: none; color: #000000 }
A:hover      {COLOR: green; FONT-FAMILY: Verdana, 宋体, MingLiU; 
TEXT-DECORATION: underline
}
body         {font-size: 10.5pt; font-family: Verdana,宋体,MingLiU, Arial;color: #000000}
TD           {FONT-SIZE: 10.5pt; FONT-FAMILY: Verdana, 宋体, MingLiU, Arial;
color: #000000;line-height: 120%;table-layout:fixed;word-break:break-all
}
p            {FONT-SIZE: 10.5pt; FONT-FAMILY: Verdana, 宋体, MingLiU, Arial;
color: #000000
}
input        {FONT-SIZE: 10.5pt; FONT-FAMILY: Verdana, 宋体, MingLiU, Arial;
color: #000000
}
body         {margin-top: 0; margin-bottom: 0;margin-left:0;margin-right:0; color: #000000}
select       {FONT-SIZE: 10.5PT;font-family: Verdana,宋体}
option       {FONT-SIZE: 10.5pt;font-family: Verdana,宋体}
textarea     {FONT-SIZE: 10.5pt;font-family: Verdana,宋体}
-->
</STYLE>
</head>
<%


if request("lm")<>"" or request("title")<>"" or request("content")<>"" then

  lm=trim(request("lm"))
  aaa=split(lm,"|")
  lm1=aaa(0)
  lm2=aaa(1)
  lm3=aaa(2)
  title=trim(request("title"))
  htitle=trim(request("htitle"))
  if htitle="" then htitle="&nbsp;"
  title=replace(title,"""","")
  title=replace(title,"'","")
  content=request("content")
  tj=trim(request("tj"))
  html=trim(request.Form("html"))
  zz=trim(request("zz"))
  tuwen=trim(request("tuwen"))
  ztid=trim(Request("ztid"))
  if (not isNumeric(ztid)) then
  	ztid=0
  end if
  url=trim(request("url"))
  GoogleMap=trim(Request("GoogleMap"))
  titlecolor=trim(request("titlecolor"))
  pic=trim(request("pic"))
  xgnews=trim(request("xgnews"))
  addtime=trim(Request("addtime"))
  hit=trim(Request("hit"))
  if addtime="" then addtime=now()
  if (not isDate(addtime)) then
    Response.Write "<Script Language=JavaScript>alert('日期/时间格式不正确 "&addtime&"');</Script> <meta http-equiv='refresh' content='0; url=javascript:window.history.go(-1);'>"
    response.end  
  end if
  laiyuan=trim(request("laiyuan"))
  piczz=trim(request("piczz"))
  
    if (not isNumeric(hit)) then
    	hit=1
	end if
  ontop=trim(request("ontop"))
  if ontop<>"5" then ontop=3
  ontop=int(ontop)
  if zz="" then zz=" "
  if piczz="" then piczz=" "
  if laiyuan="" then laiyuan=" "
  if url="" then url=" "
  if tj="" then tj="不推荐"

  
  if pic="" then
	  nr=content
	  nr=replace(nr,"<IMG","<img")
	  nr=replace(nr,"SRC=","src=")
	  nr=replace(nr,"","")
	  nr=replace(nr,"","")
	  nr=replace(nr,"","")
	  if instr(nr,"<img")<>0 and instr(nr,"src=")<>0 then
	     nr=replace(nr,"""","")
	     aa=Split(nr,"<img")
	     bb=aa(1)
	     cc=split(bb,">")
	     dd=cc(0)
	     ee=split(dd,"src=")
	     ff=ee(1)
	     gg=split(ff," ")
	     if tuwen="1" then
	       pic=gg(0)
	     end if
	  end if
  end if
   if pic="" then pic=" "
  

  if Request.Cookies("admindj")="3" then
	  if config("lrySH")=0 then
	  	sh=2
	  	
	  else
	   sh=1
	  end if
  else
  	sh=1
  end if
    
  addtime=formatdatetime(addtime,0)




  
 if request("id")="" then
 
		'conn.Execute "insert into [News] ([updat],[time],[adduser],[hit],[lm],[lm2],[lm3],[title],[htitle],[titlecolor],[content],[zz],[tj],[pic],[url],[xgnews],[ontop],[sh]) values('"&addtime&"','"&addtime&"','"&session("kuang5__user")&"',0,'"&lm1&"','"&lm2&"','"&lm3&"','"&title&"','"&htitle&"','"&titlecolor&"','"&content&"','"&zz&"','"&tj&"','"&pic&"','"&url&"','"&xgnews&"',"&ontop&","&sh&")"

		  if html="1" then
		  	Response.Cookies ("html")="1"
			dddd=year(now())&"/"&month(now())
			filename="html/"&dddd&"/"
			bbbhtml="html/"&dddd
			
		  else
		    filename="0"

		    Response.Cookies ("html")="0"
		  end if

		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select top 1 * from [news] order by id desc",conn,1,3
		 rs.addnew
		 	
		 	rs("time")=addtime
		 	rs("adduser")=session("kuang5__user")
		 	rs("hit")=hit
		 	rs("lm")=lm1
		 	rs("lm2")=lm2
		 	rs("lm3")=lm3
		 	rs("title")=title
		 	rs("htitle")=htitle
		 	rs("titlecolor")=titlecolor
		 	rs("content")=content
		 	rs("zz")=zz
		 	rs("laiyuan")=laiyuan
		 	rs("piczz")=piczz
		 	rs("ztid")=ztid
		 	rs("tj")=tj
		 	rs("pic")=pic
		 	rs("html")=html
		 	rs("url")=url
		 	rs("xgnews")=xgnews
		 	rs("ontop")=ontop
		 	rs("sh")=sh
			rs.update
		 
		 	newsid=rs("id")
		 	an=newsid
			if filename<>"0" then filename=filename&rs("ID")&".htm"
			conn.Execute "update [News] set [filename]='"&filename&"' where id="&clng(newsid)
		
		
		rs.close:set rs=nothing
		 
		 
		 	conn.Execute "update [news] set [updat]="&newsid&" where id="&clng(newsid)
		 
		  if sh=2 then 
		  	Response.Write "<script>alert('请等待管理审核，审核之前，你仍然可以编辑文章。');</script>"
		  end if
    
  else
 
		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select top 1 * from [news] where id="&trim(Request("id"))&" order by id desc",conn,1,3
		 	rs("lm")=lm1
		 	rs("lm2")=lm2
		 	rs("lm3")=lm3
		 	rs("title")=title
		 	rs("htitle")=htitle
		 	rs("titlecolor")=titlecolor
		 	rs("content")=content
		 	rs("zz")=zz
		 	rs("laiyuan")=laiyuan
		 	rs("piczz")=piczz
		 	rs("ztid")=ztid
		 	rs("tj")=tj
		 	rs("pic")=pic
		 	rs("url")=url
		 	rs("xgnews")=xgnews
		 	rs("html")=html
		 	rs("ontop")=ontop
		 	rs("sh")=sh
		 	rs("time")=addtime
		 	rs("hit")=hit
		 	
		  if html="1" then
		  	Response.Cookies ("html")="1"		
			dddd=year(rs("time"))&"/"&month(rs("time"))
			Randomize
			an=""
			an=trim(request("id"))
			if an="" then an= int((999-111+1) * RND +111)
			
			aaahtml=an
			
			if rs("filename")<>"0" then
				filename=rs("filename")
			else
				filename="html/"&dddd&"/"&aaahtml&".htm"
			end if
			
			bbbhtml="html/"&dddd
		  else
		    filename="0"
		    sdDel(rs("filename"))
		    Response.Cookies ("html")="0"
		  end if
		  	
		    rs("filename")=filename
		 rs.update
		 	newsid=rs("id")

		 rs.close:set rs=nothing
		 
		  if sh=2 then 
		  	Response.Write "<script>alert('请等待管理审核，审核之前，你仍然可以编辑文章。');</script>"
		  end if
  end if

end if
	

tgid=trim(request("tgid"))
if tgid<>"" then
	conn.Execute "delete from [usertougao] where ID="&CInt(tgid)
end if


lmid=lm3
if lmid="0" or lmid="" then lmid=lm2
if lmid="0" or lmid="" then lmid=lm1


			
%>
<p>
<br><br><br><br><Center><a href=admin/kuang5_news_add.asp?lmid=<%=lmid%>&titlecolor=<%=titlecolor%>>
保存成功，正在返回中.....</a></Center>
<!--#include file = xml-BaiDu.ASP -->


<META http-equiv="refresh" content="0;url=admin/kuang5_news_add.asp?lmid=<%=lmid%>&titlecolor=<%=titlecolor%>">


<%

ccc=filename

if bbbhtml<>"" and filename<>"" and html="1" then

	if instr(content,"$$分页$$")<>0 then
		nrfy=split(content,"$$分页$$")
		content=nrfy(page)
		fy=1
		
		for i=0 to ubound(nrfy)
			
			if i<>0 then 
				bbb=an&"-"&i+1&".htm"
			else
				bbb=an&".htm"
			end if
			ccc=bbb
					
			ddd=ddd&"<a href="&CCC&">"&i+1&"</a>&nbsp;"
		next
		
		for i=0 to ubound(nrfy)
		
			CNR=nrfy(i)&"<center>第&nbsp;"&ddd&"页</center>"
			

			BuildPath Replace(Server.MapPath(bbbhtml),"\","/") 
		
			if i<>0 then 
				bbb=an&"-"&i+1&".htm"
			else
				bbb=an&".htm"
			end if
			ccc=bbbhtml&"/"&bbb
			if content<>"" then
				
				
				
				set fso = Server.CreateObject("Scripting.FileSystemObject")
				set fout = fso.CreateTextFile(server.mappath(ccc),2,true)
				fout.write nrreplace(CNR)
			
				fout.close
				set fout=nothing
				set fso=nothing
			end if
		
		next
		
	else	'没有分页符
		
		
	
		BuildPath Replace(Server.MapPath(bbbhtml),"\","/") 
	
		if content<>"" then
						
			'filename=Replace(Server.MapPath(bbbhtml),"\","/") & filename

			
			set fso = Server.CreateObject("Scripting.FileSystemObject")
			set fout = fso.CreateTextFile(server.mappath(filename),2,false)
			fout.write nrreplace(content)
		
		fout.close
		set fout=nothing
		set fso=nothing
		end if
	end if
end if

conn.close
set conn=nothing
%>