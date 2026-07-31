<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<STYLE type="text/css">
<!--
a:link {text-decoration: none; font-family: AdobeSm; color: #000000 }
a:visited {text-decoration: none; color: #000000 }
A:hover {COLOR: green; FONT-FAMILY: "宋体,MingLiU"; TEXT-DECORATION: underline}
body {font-size: 9pt; font-family: 宋体,MingLiU, Arial;color: #000000}
TD {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000;line-height: 120%;table-layout:fixed;word-break:break-all}
p {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000}
input {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000}
body {margin-top: 0; margin-bottom: 0;margin-left:0;margin-right:0; color: #000000}
select {FONT-SIZE: 9PT;font-family: 宋体}
option {FONT-SIZE: 9pt;font-family: 宋体}
textarea {FONT-SIZE: 9pt;font-family: 宋体}
-->
</STYLE>
<%
'ON ERROR RESUME NEXT
lm=trim(request("lm2"))
if lm="" then lm=0
if (not isNumeric(lm)) then
	lm=0
end if

path=config("path")

w=trim(Request("w"))
h=trim(Request("h"))
n=trim(Request("n"))

if w="" then w=200
if h="" then h=160
if n="" then n=28

n=int(n)


function qxalttu(nr)
	nr=trim(nr)
	nr=replace(nr,"ALT","alt")
	nr=replace(nr,"ALT","alt")
	nr=replace(nr,"ALT","alt")
	nr=replace(nr,"ALT","alt")
	nr=replace(nr,"ALT","alt")
	if instr(nr," ")<>0 then
		aaa=split(nr," ")
		nr=aaa(0)
	end if
	qxalttu=nr
end function


function titlepic(nr)
	nr=trim(nr)
	nr=replace(nr," ","")	
	nr=replace(nr,"""","")
	titlepic=titleb(nr,n)
end function


set rs = server.CreateObject ("adodb.recordset")
sql = "select top 6 id,title,pic,lm,lm2,lm3,filename from news where ( pic like '%.jpg%' or pic like '%.JPG%' ) and sh=1 "
if lm<>"0" then sql=sql&" and (lm='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"') "
sql=sql&" order by ontop desc , id desc"
rs.open sql,conn,1,1
if rs.recordcount=0 then
  Response.Write "<BR><center>无图片信息</center>"
  rs.close:set rs=nothing
  conn.close:set conn=nothing
  Response.end
end if

for i=1 to rs.recordcount
	
	pic1=qxalttu(rs("pic"))
	title1=titleb(rs("title"),n)
	id1=rs("id")
	filename1=rs("filename")
	rs.movenext
	if rs.eof then exit for
	
	pic2=qxalttu(rs("pic"))
	title2=titleb(rs("title"),n)
	id2=rs("id")
	filename2=rs("filename")
	rs.movenext
	if rs.eof then exit for
	
	pic3=qxalttu(rs("pic"))
	title3=titleb(rs("title"),n)
	id3=rs("id")
	filename3=rs("filename")
	rs.movenext
	if rs.eof then exit for
	
	pic4=qxalttu(rs("pic"))
	title4=titleb(rs("title"),n)
	id4=rs("id")
	filename4=rs("filename")
	rs.movenext
	if rs.eof then exit for
	
	pic5=qxalttu(rs("pic"))
	title5=titleb(rs("title"),n)
	id5=rs("id")
	filename5=rs("filename")
	rs.movenext
	if rs.eof then exit for
	
	pic6=qxalttu(rs("pic"))
	title6=titleb(rs("title"),n)
	id6=rs("id")
	filename6=rs("filename")
	rs.movenext
	if rs.eof then exit for	
	
next

rs.close
set rs=nothing 


if trim(filename1)<>"0" then
	url1=path&filename1
else
	url1=path&"News_View.asp?newsid="&id1
end if

if trim(filename2)<>"0" then
	url2=path&filename2
else
	url2=path&"News_View.asp?newsid="&id2
end if

if trim(filename3)<>"0" then
	url3=path&filename3
else
	url3=path&"News_View.asp?newsid="&id3
end if

if trim(filename4)<>"0" then
	url4=path&filename4
else
	url4=path&"News_View.asp?newsid="&id4
end if

if trim(filename5)<>"0" then
	url5=path&filename5
else
	url5=path&"News_View.asp?newsid="&id5
end if

if trim(filename6)<>"0" then
	url6=path&filename6
else
	url6=path&"News_View.asp?newsid="&id6
end if


%>

<a target=_blank href="javascript:goUrl()"> 
                    <span class="f14b">
                    <script type="text/javascript">
imgUrl1="<%=pic1%>";
imgtext1="<%=title1%>";
imgLink1=escape("<%=url1%>");
imgUrl2="<%=pic2%>";
imgtext2="<%=title2%>";
imgLink2=escape("<%=url2%>");
imgUrl3="<%=pic3%>";
imgtext3="<%=title3%>";
imgLink3=escape("<%=url3%>");
imgUrl4="<%=pic4%>";
imgtext4="<%=title4%>";
imgLink4=escape("<%=url4%>");
imgUrl5="<%=pic5%>";
imgtext5="<%=title5%>";
imgLink5=escape("<%=url5%>");
imgUrl6="<%=pic6%>";
imgtext6="<%=title6%>";
imgLink6=escape("<%=url6%>");

 var focus_width=<%=w%>
 var focus_height=<%=h%>
 var text_height=20
 var swf_height = focus_height+text_height
 
 var pics=imgUrl1+"|"+imgUrl2+"|"+imgUrl3+"|"+imgUrl4+"|"+imgUrl5+"|"+imgUrl6
 var links=imgLink1+"|"+imgLink2+"|"+imgLink3+"|"+imgLink4+"|"+imgLink5+"|"+imgLink6
 var texts=imgtext1+"|"+imgtext2+"|"+imgtext3+"|"+imgtext4+"|"+imgtext5+"|"+imgtext6
 
document.write('<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,0,0" width="'+ focus_width +'" height="'+ swf_height +'">');
document.write('<param name="allowScriptAccess" value="sameDomain"><param name="movie" value="playswf.swf"><param name=wmode value=transparent><param name="quality" value="high">');
document.write('<param name="menu" value="false"><param name=wmode value="opaque">');
document.write('<param name="FlashVars" value="pics='+pics+'&links='+links+'&texts='+texts+'&borderwidth='+focus_width+'&borderheight='+focus_height+'&textheight='+text_height+'">');
document.write('<embed src="playswf.swf" wmode="opaque" FlashVars="pics='+pics+'&links='+links+'&texts='+texts+'&borderwidth='+focus_width+'&borderheight='+focus_height+'&textheight='+text_height+'" menu="false" bgcolor="#DADADA" quality="high" width="'+ focus_width +'" height="'+ swf_height +'" allowScriptAccess="sameDomain" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />');  document.write('</object>');
//-->
</script> 
</span></a><span id=focustext class=f14b> </span>
<body>
</body>
</html>
