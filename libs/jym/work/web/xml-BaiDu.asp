
<%
'conn.execute "ALTER TABLE [config] add WebEmail text(100)"
Function RemoveHTML(strHTML) 
Dim objRegExp, Match, Matches 
Set objRegExp = New Regexp 
objRegExp.IgnoreCase = True 
objRegExp.Global = True 
'取闭合的<>
objRegExp.Pattern = "<.+?>" 
'进行匹配 
Set Matches = objRegExp.Execute(strHTML) 
' 遍历匹配集合，并替换掉匹配的项目 
For Each Match in Matches 
strHtml=Replace(strHTML,Match.Value,"") 
Next 

strHTML=replace(strHTML,"&nbsp;","")
strHTML=replace(strHTML,"&","&amp;")
strHTML=replace(strHTML,"'","&apos;")
strHTML=replace(strHTML,"""","&quot;")
strHTML=replace(strHTML,">","&gt;")
strHTML=replace(strHTML,"<","&lt;")

RemoveHTML=strHTML 
Set objRegExp = Nothing 
End Function

function hrefIDD(ID,filename)
	if filename<>"0" then
		hrefidD=""&filename
	else
		hrefidD="News_View.asp?NewsID="&ID
	end if
end function

pencat="<?xml version=""1.0"" encoding=""GB2312"" ?>"
pencat=pencat & "<document>"
pencat=pencat & "<webSite>"&Request.ServerVariables("SERVER_NAME")&"</webSite>"
pencat=pencat & "<webMaster>"&config("WebEmail")&"</webMaster>"
pencat=pencat & "<updatePeri>50</updatePeri>"

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select top 50 * from news where sh=1 order by id desc",conn,1,1
do while not rs.eof 
author=rs("zz")
dates=rs("time")
title=removehtml(rs("title"))
laiyuan=rs("laiyuan")
filename=rs("filename")
pic=rs("pic")
id=rs("id")
abcd=rs("content")
abc=abcd
temp=left(removehtml(abc),200)

content=removehtml(abc)

pencat=pencat & "<item>"
pencat=pencat & "<title>"&title&"</title>"
pencat=pencat & "<link>http://"&Request.ServerVariables("SERVER_NAME")&config("path")&hrefIDD(ID,filename)&"</link>"
pencat=pencat & "<description>"&temp&"……</description>"
pencat=pencat & "<text>"&content&"</text>"

pencat=pencat & "<image>"&pic&"</image>"

if pic=" " or pic="" or pic="  " then
	pencat=pencat & "<source>狂舞网</source>"
else 
	pencat=pencat & "<source>"&laiyuan&"</source>"
end if

pencat=pencat & "<author>"&author&"</author>"
pencat=pencat & "<pubDate>"&dates&"</pubDate>"
pencat=pencat & "</item>"

rs.movenext 
loop
rs.close
set rs=nothing
pencat=pencat & "</document>"

'################ 读取并保存结束 ################
Set fso = Server.CreateObject("Scripting.FileSystemObject")
Set fout = fso.CreateTextFile(server.mappath("xml-BaiDu.xml"))
fout.Write pencat
fout.close
'************** 生成HTML页 结束 ***************

'response.Redirect("xml-BaiDu.xml")
%>
