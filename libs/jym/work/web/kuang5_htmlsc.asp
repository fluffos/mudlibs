
<%
Server.ScriptTimeOut = 600

if Request.Cookies("admindj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<html>

<head>
<!--#include file = language.asp -->

</head>
<body>
<%
lm=chkhtm(trim(request("lm")))
html=1
iii=0
if (not isNumeric(lm)) then
  Response.Write "<Script Language=JavaScript>alert('栏目参数错误或有非法字符或没指定参数，请勿随意提交数据！');</Script>"
  response.end  
end if
		conn.Execute "update [news] set [zz]=' ' where zz='' or zz='&nbsp;' or zz is null "
		conn.Execute "update [news] set [laiyuan]=' ' where laiyuan='' or laiyuan='&nbsp;' or laiyuan is null "
		conn.Execute "update [news] set [piczz]=' ' where piczz='' or piczz='&nbsp;' or piczz is null "	
set rshtml = Server.CreateObject("ADODB.RecordSet")
rshtml.Open "select * from [News] where ( LM='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"' ) and sh=1 and [filename]='0' order by id desc",conn,1,1
while not rshtml.eof
			piczz=""
			zz=""
			title=""
			laiyuan=""
		  	Response.Cookies ("html")="1"		
			dddd=year(rshtml("time"))&"/"&month(rshtml("time"))
			an=rshtml("ID")		
			aaahtml=an
			content=rshtml("content")
			lm3=rshtml("lm3")
			lm2=rshtml("lm2")
			lm1=rshtml("lm")
			title=rshtml("title")
			addtime=rshtml("time")
			laiyuan=rshtml("laiyuan")
			piczz=rshtml("piczz")
			zz=rshtml("zz")
			newsid=rshtml("id")
			
			'Response.end
			
			if len(trim(laiyuan))=0 then laiyuan="&nbsp;"
			if zz="" then zz="&nbsp;"
			if piczz="" then piczz="&nbsp;"
			if rshtml("filename")<>"0" then
				filename=rshtml("filename")
			else
				filename="html/"&dddd&"/"&aaahtml&".htm"
			end if
			
			bbbhtml="html/"&dddd
			
			schtml
			conn.Execute "update [news] set [filename]='"&filename&"',[html]=1 where id="&clng(rshtml("id"))
			
			iii=iii+1
rshtml.movenext
wend
rshtml.close:set rshtml=nothing
%>
</body>
<script>
alert('共生成文章<%=iii%>条');
history.back();
</script>

</html>

<%
conn.close:set conn=nothing
%>