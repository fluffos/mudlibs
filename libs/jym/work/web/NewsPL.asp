<!--#include file = kuang5_conn.asp -->
<%
id=trim(request("id"))

if (not isNumeric(ID)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数，请勿随意提交数据！');</Script>"
  response.end  
end if

sql = "select id,title from news where id="&clng(ID)
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
if rs.recordcount<>0 then
	title=rs("title")
end if
rs.close
set rs=nothing

sql = "select * from newspl where newsid="&clng(id)
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
%>

<html>

<head>
<!--#include file = language.asp -->
<title>查看发表评论 <%=title%></title>
<STYLE type="text/css">
<!--
a:link       {text-decoration: none; font-family: AdobeSm; color: #000000 }
a:visited    {text-decoration: none; color: #000000 }
A:hover      {COLOR: green; FONT-FAMILY: "宋体,MingLiU"; TEXT-DECORATION: underline}
body         {font-size: 9pt; font-family: 宋体,MingLiU, Arial;color: #000000}
TD           {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000;table-layout:fixed;word-break:break-all}
p            {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000}
input        {FONT-SIZE: 9pt; FONT-FAMILY: "宋体,MingLiU, Arial";color: #000000}
body         {margin-top: 0; margin-bottom: 0;margin-left:0;margin-right:0; color: #000000}
select       {FONT-SIZE: 9PT;}
option       {FONT-SIZE: 9pt;}
textarea     {FONT-SIZE: 9pt;}
-->
</STYLE>
</head>

<body>

<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.username.value = "") Then
    MsgBox "请在 作者 域中输入值。", 0, "有效性验证错误"
    theForm.username.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.username.value) < 2) Then
    MsgBox "在 作者 域中，请至少输入 2 个字符。", 0, "有效性验证错误"
    theForm.username.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.username.value) > 8) Then
    MsgBox "在 作者 域中，请最多输入 8 个字符。", 0, "有效性验证错误"
    theForm.username.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.content.value = "") Then
    MsgBox "请在 评论 域中输入值。", 0, "有效性验证错误"
    theForm.content.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.content.value) < 5) Then
    MsgBox "在 评论 域中，请至少输入 5 个字符。", 0, "有效性验证错误"
    theForm.content.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.content.value) > 200) Then
    MsgBox "在 评论 域中，请最多输入 200 个字符。", 0, "有效性验证错误"
    theForm.content.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="NewsPL_save.asp?id=<%=id%>" name="FrontPage_Form1">
	<div align="center">
		<table border="1" cellpadding="5" width="500" id="table1" style="border-collapse: collapse" bordercolor="#C0C0C0" bgcolor="#F5F5F5">
			<tr>
				<td width="109" align="center">作者</td>
				<td>
				&nbsp;<!--webbot bot="Validation" s-display-name="作者" b-value-required="TRUE" i-minimum-length="2" i-maximum-length="8" --><input type="text" name="username" size="20" style="background-color: #F5F5F5" maxlength="8"></td>
			</tr>
			<tr>
				<td width="109" align="center" bgcolor="#FFFFFF">评论</td>
				<td bgcolor="#FFFFFF">
				&nbsp;<!--webbot bot="Validation" s-display-name="评论" b-value-required="TRUE" i-minimum-length="5" i-maximum-length="200" --><textarea rows="4" name="content" cols="67"></textarea></td>
			</tr>
			</table>
	</div>
	<p align="center"><input type="submit" value="提交" name="B1">&nbsp;&nbsp;&nbsp; <input type="reset" value="重置" name="B2"></p>
</form>

<div align="center">
	<table border="0" cellpadding="3" cellspacing="0" width="500" id="table2">
	<%
	if rs.recordcount<>0 then
	
	page=int(request("page"))
rs.PageSize=10
pagecount=rs.pagesize
if page<=0 then page=1
if request("page")="" then page=1
rs.AbsolutePage=page

 for i=1 to pagecount
 
 content=rs("content")
 content=replace(content,chr(10),"")
content=replace(content,chr(13),"<BR>")
	%>
		<tr>
			<td bgcolor="#F5F5F5" style='word-break:break-all'>
			<img border="0" src="images/bbstitle.gif" width="16" height="15"><font color="#336699"><%=rs("username")%></font>　于　<%=rs("addtime")%></td>
		</tr>
		<tr>
			<td><%=content%></td>
		</tr>
	<%
	rs.movenext
	if rs.eof then exit for
	next
else
  Response.Write "<tr><td>暂无评论！</td></tr>"
end if
	%>
	</table>
</div>
<br>
<center>
<%if rs.recordcount<>0 then
  if page>1 then
    response.write "<a href="&request.servervariables("URL")&"?page=1&id="&id&">首页</a>　"
    response.write "<a href="&request.servervariables("URL")&"?page="&page-1&"&id="&id&">上一页</a>　"
  end if
  if page<rs.pagecount then
    response.write "<a href="&request.servervariables("URL")&"?page="&page+1&"&id="&id&">下一页</a>　"
    response.write "<a href="&request.servervariables("URL")&"?page="&rs.pagecount&"&id="&id&">尾页</a>　"
  end if
    response.write "共"&rs.recordcount&"条　每页显示"&pagecount&"条　共"&rs.pagecount&"页　"
  %>
  <script language="JavaScript">
  <!--
  function FP_jumpMenu(el,frm,sel) {//v1.0
    var href=el.options[el.selectedIndex].value; if(sel) el.selectedIndex=0;
    if('_new'==frm) open(href); else eval(frm+".location='"+href+"'");
    }
    // -->
  </script>
  <select size="1" onchange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="font-size: 9pt; border-style: solid; border-width: 1px">
   <%for i=1 to rs.pagecount%>
   <option value="<%=request.servervariables("URL")%>?page=<%=i%>&id=<%=id%>" <%if page=i then response.write "selected"%> style="font-size: 9pt">第<%=i%>页</option>
    <%next%>
   </select>
<%end if%>
</center>
</body>

</html>
<%
rs.close
set rs=nothing
conn.close
set conn=nothing
%>