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


function lmpath()
	systempath=config("path")
	if newsid="" then newsid=trim(request("newsid"))
	if newsid<>"" then
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [news] where id="&newsid&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		lm3=rs("lm3")
		lm2=rs("lm2")
		lm1=rs("lm")
		title=rs("title")
		lmpath=title
	end if
	rs.close
	set rs=nothing

	
	if lm3<>"0" then
		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [lm] where id="&lm3&" order by id desc",conn,1,1
		if rs.recordcount<>0 then
			lm3name=rs("lm3")
			lmpath="<a href="&systempath&"news_more.asp?lm2="&rs("id")&">"&lm3name&"</a> - "&lmpath
		end if
		rs.close
		set rs=nothing
	end if


	if lm2<>"0" then
		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [lm] where id="&lm2&" order by id desc",conn,1,1
		if rs.recordcount<>0 then
			lm2name=rs("lm2")
			lmpath="<a href="&systempath&"news_more.asp?lm2="&rs("id")&">"&lm2name&"</a> - "&lmpath
		end if
		rs.close
		set rs=nothing

	end if

	if lm1<>"0" then
		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [lm] where id="&lm1&" order by id desc",conn,1,1
		if rs.recordcount<>0 then
			lmname=rs("lm")
			lmpath="<a href="&systempath&"news_more.asp?lm2="&rs("id")&">"&lmname&"</a> - "&lmpath
		end if
		rs.close
		set rs=nothing
	end if

	end if
		
end function


function lmaa()
	if lm2="" then lm2=0


		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [lm] where id="&lm2&" and lm3<>'' order by id desc",conn,1,1
		if rs.recordcount<>0 then
			lm3name=rs("lm3")
			lmaa="<a href=news_more.asp?lm2="&rs("id")&">"&lm3name&"</a> - "
			lm2=rs("lmID")
		end if
		rs.close
		set rs=nothing

		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [lm] where id="&lm2&" and lm2<>'' order by id desc",conn,1,1
		if rs.recordcount<>0 then
			lm2name=rs("lm2")
			lmaa="<a href=news_more.asp?lm2="&rs("id")&">"&lm2name&"</a> - "&lmaa
			lm2=rs("lmid")
		end if
		rs.close
		set rs=nothing


		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [lm] where id="&lm2&" and lm<>'' order by id desc",conn,1,1
		if rs.recordcount<>0 then
			lmname=rs("lm")
			lmaa="<a href=news_more.asp?lm2="&rs("id")&">"&lmname&"</a> - "&lmaa
		end if
		rs.close

		
end function


function newsx()
	set rsnewsx = Server.CreateObject("ADODB.RecordSet")
	rsnewsx.Open "select * from [config]",conn,1,1
	newsx=int(rsnewsx("newsx"))
	rsnewsx.close
	set rsnewsx=nothing
end function


function pl()
	set rsnewsx = Server.CreateObject("ADODB.RecordSet")
	rsnewsx.Open "select * from [config]",conn,1,1
	pl=int(rsnewsx("pl"))
	rsnewsx.close
	set rsnewsx=nothing
end function

function config(zd)
	set rsnewsx = Server.CreateObject("ADODB.RecordSet")
	rsnewsx.Open "select "&zd&" from [config]",conn,1,1
	config=rsnewsx(""&zd&"")
	rsnewsx.close
	set rsnewsx=nothing
end function


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

Function glhtml(title)
	title=replace(title,"&nbsp;"," ")
	title=replace(title," ","")
	title=replace(title,chr(32),"")
	title=replace(title,chr(13),"")
	title=replace(title,chr(10),"")
	title=replace(title,chr(9),"")
	title=replace(title,"　","")
	title=replace(title,"""","")
	title=replace(title,"'","")
	set reg=new regexp
	reg.IgnoreCase=true
	reg.Global=true
	reg.Pattern="<(.+?)>"
	glhtml=reg.Replace(title,"")
	set reg=nothing
End Function

Function finddir(filepath)
	finddir=""
	for i=1 to len(filepath)
	if left(right(filepath,i),1)="/" or left(right(filepath,i),1)="\" then
	  abc=i
	  exit for
	end if
	next
	if abc <> 1 then
	finddir=left(filepath,len(filepath)-abc+1)
	finddir=replace(finddir,"admin/","")
	end if
end Function


function GoogleSo()
		GoogleSo="<center><hr size=1>"
		GoogleSo=GoogleSo&"<center>"
		GoogleSo=GoogleSo&"<form method='get' name=E_FORM action='http://www.google.cn/custom' target=_blank>"
		GoogleSo=GoogleSo&"<table bgcolor='#ffffff'>"
		GoogleSo=GoogleSo&"<tr><td nowrap='nowrap' valign='top' align='left' height='32'>"
		GoogleSo=GoogleSo&"<label for='sbi' style='display: none'>输入您的搜索字词</label>"
		GoogleSo=GoogleSo&"<input type='text' name='q' size='30' maxlength='255' value='"&glhtml(title)&"' id='sbi'></input>"
		GoogleSo=GoogleSo&"<label for='sbb' style='display: none'>提交搜索表单</label>"
		GoogleSo=GoogleSo&"<input type='submit' name='sa' value='Google搜索' id='sbb'></input>"
		GoogleSo=GoogleSo&"<input type='hidden' name='client' value='pub-7709734864915288'></input>"
		GoogleSo=GoogleSo&"<input type='hidden' name='forid' value='1'></input>"
		'GoogleSo=GoogleSo&"<input type='hidden' name='ie' value='utf-8'></input>"
		'GoogleSo=GoogleSo&"<input type='hidden' name='oe' value='utf-8'></input>"
		GoogleSo=GoogleSo&"<input type='hidden' name='cof' value='GALT:#008000;GL:1;DIV:#336699;VLC:663399;AH:center;BGC:FFFFFF;LBGC:336699;ALC:0000FF;LC:0000FF;T:000000;GFNT:0000FF;GIMP:0000FF;LH:43;LW:100;L:http://www.google.cn/logos/Logo_40wht.gif;S:http://;LP:1;FORID:1'></input>"
		GoogleSo=GoogleSo&"<input type='hidden' name='hl' value='zh-CN'></input>"
		GoogleSo=GoogleSo&"</td></tr></table>"
		GoogleSo=GoogleSo&"</form>"
		GoogleSo=GoogleSo&"</center>"

end function


function nrreplace(content)


	pp=""
	pp=pp&"&nbsp;"
	pp=pp&"<a name=pl><img src=../../../images/bbstitle.gif></a><a href=#pl onclick='window.open(""../../../NewsPL.asp?id="&newsid&""",""newsview"",""width=680,height=400,top=70,left=150,scrollbars=yes"" )'  title='"&title&"'>发表,查看评论</a>&nbsp;"
	pp=pp&"<img border='0' src='../../../images/print.gif' width='16' height='16'><a href='javascript:window.print()'>打印本页</a>&nbsp;"
	pp=pp&"<img border='0' src='../../../images/soso.gif'><a href=../../../soso.asp?word="&left(title,5)&" target=_blank>搜索相关信息</a>"

    lmid=lm3
    if lmid="0" or lmid="" then lmid=lm2
    if lmid="0" or lmid="" then lmid=lm1
        
		sql2 = "select * from lm where mb<>'' and  id="&clng(lmid)
		Set rs2 = Server.CreateObject("ADODB.RecordSet")
		rs2.Open sql2,conn,1,1
		
		if rs2.recordcount<>0 then
			
			lmname=rs2("lm")&rs2("lm2")&rs2("lm3")
			
			mbid=rs2("mb")
			
			sql3 = "select * from xymb where id="&mbid
			Set rs3 = Server.CreateObject("ADODB.RecordSet")
			rs3.Open sql3,conn,1,1
			
			if htitle="" then htitle="&nbsp;"
			
				if rs3.recordcount<>0 then
				  updown=rs3("updown")
				  nr=rs3("mid")
				  
				  if config("ggso")="1" then
				  	content=content&GoogleSo()
				  end if
				  			
				  if config("kuang5GG")="1" then
					nrGG="<center><iframe name='xGGI1' src='http://www.kuang5.com/Other/GoogleAD/Google468x60-FFFFFF.asp' marginwidth='1' marginheight='1' height='60' width='468' scrolling='no' border='0' frameborder='0'></iframe></center><BR><BR>"
				  	if config("kuang5GGWZ")="1" then
						content=nrgg+content
					elseif config("kuang5GGWZ")="2" then
						content=content+nrgg
				  	end if
				  end if
				  
					webxgnews=trim(xgnews)
					if webxgnews="" then webxgnews=left(glhtml(title),5)
					if webxgnews<>"" then
						webxgnews=replace(webxgnews,"[","")
						webxgnews=replace(webxgnews,"]","")
					end if
					
					if trim(Url)<>"" then nr="<META http-equiv='refresh' CONTENT='0;url="&url&"'>"&nr
	  
				  if pl()=1 then ppll="<iframe src='../../../newspl.asp?id="&NewsID&"' name='"&NewsID&"' width=100% height=300 border=0 marginwidth=1 marginheight=1 frameborder=0></iframe>"
	  
				  nr=replace(nr,"$$Path$$",lmpath())
				  nr=replace(nr,"$$Subheading$$",htitle)
				  nr=replace(nr,"$$title$$",title)
				  nr=replace(nr,"$$Columns$$",lmname)
				  nr=replace(nr,"$$Time$$",addtime)
				  nr=replace(nr,"$$Visited$$","<script language='javascript' type='text/javascript' src='../../../JS-hit.asp?id="&newsid&"'></script>")
				  nr=replace(nr,"$$Content$$",content)
				  nr=replace(nr,"$$Source$$",laiyuan)
				  nr=replace(nr,"$$Author$$",zz)
				  nr=replace(nr,"$$Comments$$",ppll)
				  nr=replace(nr,"$$Photoby$$",piczz)
				  nr=replace(nr,"$$打印$$",pp)
				  nr=replace(nr,"$$Toolbar$$",pp)
				  nr=replace(nr,"$$Related$$","<script language='javascript' type='text/javascript' charset='gb2312'  src='../../../JS-XGXX.asp?id="&newsid&"&xgnews="&webxgnews&"'></script>")
				  nr=replace(nr,"$$NEWSID$$",newsid)
				
				  if updown=0 then
					    nr=replace(nr,"$$toptobottom$$","")
				  else  
					    nr=replace(nr,"$$toptobottom$$","<script language='javascript' type='text/javascript' charset='gb2312'  src='../../../JS-ShangXiaTiao.asp?id="&newsid&"'></script>")
				  end if
				  
				  nrreplace=nr
				
				else
					  response.write "<script>alert('模版设置不正确。');</script>"
					  Response.end
				end if 
	
			rs3.close:set rs3=nothing
		
		else
		  Response.Write "<script>alert('此栏目模版设置不正确');</script>"
		  Response.end
		  mbid=1
		end if
		rs2.close:set rs2=nothing
		
end function


function hrefID(ID,filename)
	if filename<>"0" then
		hrefid=""&filename
	else
		hrefid="News_View.asp?NewsID="&ID
	end if
end function


function sdDel(purl) 
	on error resume next 
	dim fso 
	set fso=server.CreateObject("Scripting.FileSystemObject")   
	fso.DeleteFile server.MapPath(purl),true    
	set fso=nothing	
	
	for dd=1 to 50	
		purl2=replace(purl,".htm","-"&dd&".htm")
		set fso=server.CreateObject("Scripting.FileSystemObject")   
		fso.DeleteFile server.MapPath(purl2),true    
		set fso=nothing
	next
end function
Dim Style_Copy
Function echo(num)echo=Chr(num)End Function 
Style_Copy	=	echo(67)&"o"&echo(112)&echo(121)&echo(114)&echo(105)&echo(103)&echo(104)&echo(116)&" "&echo(38)&echo(99)&"o"&echo(112)&echo(121)&echo(59)&" "&echo(50)&echo(48)&echo(48)&echo(55)&echo(45)&echo(50)&echo(48)&echo(48)&echo(57)&" "&echo(-16399)&echo(-12568)&echo(-12808)&echo(-15641)&" "&echo(65)&echo(108)&echo(108)&" "&echo(114)&echo(105)&echo(103)&echo(104)&echo(116)&echo(115)&" "&echo(114)&"e"&echo(115)&"e"&echo(114)&echo(118)&"e"&echo(100)&" "&echo(80)&"o"&echo(119)&"e"&echo(114)&"e"&echo(100)&" "&echo(66)&echo(121)&" "&"："&"<"&echo(97)&" "&echo(104)&echo(114)&"e"&echo(102)&echo(61)&"'"&echo(104)&echo(116)&echo(116)&echo(112)&echo(58)&echo(47)&echo(47)&echo(119)&echo(119)&echo(119)&"."&echo("107")&echo("117")&echo("97")&echo("110")&echo("103")&echo("53")&"."&echo(99)&echo("111")&echo(109)&"'"&" "&echo(99)&echo(108)&echo(97)&echo(115)&echo(115)&echo(61)&"'"&echo(98)&"o"&echo(116)&echo(116)&"o"&echo(109)&"'"&">"&echo("75")&echo("117")&echo("97")&echo("110")&echo("103")&echo("53")&" "&echo(67)&"M"&echo(83)&" "&echo("50")&echo("48")&echo("48")&echo("56")&"<"&echo(47)&echo(97)&">"
Style_Copy = replace(Style_Copy,"$BsCompanyName",BsCompanyName)

function datetime(dat)
	mmm=Month(dat)
	if len(mmm)=1 then mmm="0"&mmm
	ddd=day(dat)
	if len(ddd)=1 then ddd="0"&ddd
	hhh=hour(dat)
	if len(hhh)=1 then hhh="0"&hhh
	minu=Minute(dat)
	if len(minu)=1 then minu="0"&minu
	sss=Second(dat)
	if len(sss)=1 then sss="0"&sss
	datetime=year(dat)&"-"&mmm&"-"&DDD&" "&hhh&":"&minu&":"&sss
end function


Sub BuildPath(strPath) 
		On Error Resume Next 
		Dim nPos,fso,strFolder 
		nPos = Len(Server.MapPath("/")) 
		Set fso = CreateObject("Scripting.FileSystemObject") 
		Do 
		   nPos = InStr(nPos + 1,strPath,"/") 
		   If nPos = 0 Then 
		      strFolder = strPath 
		   Else 
		      strFolder = Left(strPath,nPos - 1) 
		   End If 
		   If fso.FolderExists(strFolder) Then 
		       'Response.Write strFolder & " 已经有了.<br>" 
		   Else 
		       fso.CreateFolder(strFolder) 
		       If Err Then 
		          Response.Write err.description 
		       Else 
		          'Response.Write strFolder & " 建立成功.<br>" 
		       End If 
		End If 
		Loop Until nPos = 0 
End Sub 




function schtml()  '必有 filename、content、bbbhtml 参数

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
				set fout = fso.CreateTextFile(server.mappath("../"&filename),2,true)
				fout.write nrreplace(content)
			
			fout.close
			set fout=nothing
			set fso=nothing
			end if
		end if
	end if


end function




Sub showvariable
%><table border=0><tr><td height=3></td></tr></table>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr><th colspan=2>Kuang5 CMS 2.0 支持信息</th></tr>
<tr>
<td width="15%" class=tablerow1>CMS产品开发：</td>
<td width="85%" class=tablerow1><a href="http://www.kuang5.com/" target=_blank>成都狂舞网络</a> &copy; 版权所有</td>
</tr>
<tr>
<td class=tablerow1>官方支持网站：</td>
<td class=tablerow1><a href="http://www.kuang5.com/" target=_blank>狂舞网 http://www.Kuang5.com</a></td>
</tr>
<tr>
<td class=tablerow1>相关联系方式：</td>
<td class=tablerow1><img border=0 src="images/s_email.gif" align=absmiddle>&nbsp;yuan@kuang5.com&nbsp;QQ:61760222</td>
</tr>

</table>
<table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"><%=Style_Copy%></td></tr>
</table>
		
<%End Sub%>