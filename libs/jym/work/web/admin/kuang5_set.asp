<%
'ON ERROR RESUME NEXT

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
<meta http-equiv="Content-Language" content="zh-cn">
<!--#include file = language.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>





		<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form2_onsubmit()
  Set theForm = document.FrontPage_Form2

  If (theForm.Newsx.value = "") Then
    MsgBox "请在 New时效 域中输入值。", 0, "有效性验证错误"
    theForm.Newsx.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.Newsx.value) < 1) Then
    MsgBox "在 New时效 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.Newsx.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.Newsx.value) > 3) Then
    MsgBox "在 New时效 域中，请最多输入 3 个字符。", 0, "有效性验证错误"
    theForm.Newsx.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  checkOK = "0123456789-" 
  checkStr = theForm.Newsx.value
  allValid = True
  validGroups = True
  decPoints = 0
  allNum = ""
  For i = 1 to len(checkStr)
    ch = Mid(checkStr, i, 1)
    If (InStr(checkOK, ch) = 0) Then
        allValid = False
        Exit For
    End If
    allNum = allNum & ch
  Next
  If (Not allValid) Then
    MsgBox "在 New时效 域中，只能输入 数字 字符。", 0, "有效性验证错误"
    theForm.Newsx.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  If ((checkstr <> "" And Not IsNumeric(allNum)) Or (decPoints > 1) Or Not validGroups) Then
    MsgBox "请在 Newsx 域中输入一个有效数字。", 0, "有效性验证错误"
    theForm.Newsx.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  If (theForm.moreline.value = "") Then
    MsgBox "请在 列表行距 域中输入值。", 0, "有效性验证错误"
    theForm.moreline.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.moreline.value) < 1) Then
    MsgBox "在 列表行距 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.moreline.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.moreline.value) > 3) Then
    MsgBox "在 列表行距 域中，请最多输入 3 个字符。", 0, "有效性验证错误"
    theForm.moreline.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  checkOK = "0123456789-" 
  checkStr = theForm.moreline.value
  allValid = True
  validGroups = True
  decPoints = 0
  allNum = ""
  For i = 1 to len(checkStr)
    ch = Mid(checkStr, i, 1)
    If (InStr(checkOK, ch) = 0) Then
        allValid = False
        Exit For
    End If
    allNum = allNum & ch
  Next
  If (Not allValid) Then
    MsgBox "在 列表行距 域中，只能输入 数字 字符。", 0, "有效性验证错误"
    theForm.moreline.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If

  If ((checkstr <> "" And Not IsNumeric(allNum)) Or (decPoints > 1) Or Not validGroups) Then
    MsgBox "请在 moreline 域中输入一个有效数字。", 0, "有效性验证错误"
    theForm.moreline.focus()
    FrontPage_Form2_onsubmit = False
    Exit Function
  End If
  FrontPage_Form2_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_set_newsxg.asp?wz=newsxg" name="FrontPage_Form2">
<%
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [config] ",conn,1,1
%><table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
			<th colspan="3">
			网站相关设置</th>
		</tr><tr><td>
<fieldset style="cursor: default"><legend>&nbsp;网站基本信息</legend>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="TableBorder2">
<tr>
<td width="167" class="TableRow1" align="right">网站名称：</td>
<td width="415" height="25" class="TableRow1"><input size="50" name="webname" value="<%=rs("webname")%>"> </td><td class="TableRow1">如：狂舞网</td>
</tr>
<tr>
<td width="167" class="TableRow1" align="right">网站地址：</td>
<td width="415" height="25" class="TableRow1"><input size="50" name="domain" value="<%=rs("domain")%>"></td><td class="TableRow1"> 如：http://www.kuang5.com/</td>
</tr>
<tr>
<td width="167" class="TableRow1" align="right">网站标题：</td>
<td width="415" height="25" class="TableRow1"><input size="50" name="webtit" value="<%=rs("webtit")%>"></td><td class="TableRow1"> </td>
</tr>
<tr> 
<td width="167" class="TableRow1" align="right">搜索关键字：</td>
<td width="415" height="25" class="TableRow1"><input size="50" name="keyword" value="<%=rs("keyword")%>"></td><td class="TableRow1"> 便于搜索引擎收录 用","隔开</td>
</tr>
<tr>
<td width="167" class="TableRow1" align="right">ICP备案号：</td>
<td width="415" height="25" class="TableRow1"><input size="50" name="icp" value="<%=rs("icp")%>"></td><td class="TableRow1"> .</td>
</tr>
<tr>
<td width="167" class="TableRow1" align="right">客服信息：</div></td>
<td width="415" height="25" class="TableRow1"><textarea name="kefu" style="display:none"><%=rs("kefu")%></textarea>
<iframe ID="eWebEditor1" src="../edit/ewebeditor.htm?id=kefu&style=coolblue" frameborder="5" scrolling="no" width="100%" HEIGHT="300"></iframe>
</td><td class="TableRow1"> 填写游戏客服信息,QQ\电话等</td>
</tr>
		</table></fieldset></td></tr>
		
		<tr><td>
		<fieldset style="cursor: default"><legend>&nbsp;设置中心</legend>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="TableBorder2">
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			<img border="0" src="../images/new.gif" width="28" height="11">时效</td>
			<td bgcolor="#F8F8F8" width="350" background="../images/bj3.jpg" height="25">
			
				<p>
				&nbsp;<!--webbot bot="Validation" s-display-name="New时效" s-data-type="Integer" s-number-separators="x" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="3" --><input type="text" value='<%=rs("newsx")%>' name="Newsx" size="6" maxlength="3"> 天</p>
			
			</td>
			<td bgcolor="#F8F8F8" width="250" background="../images/bj3.jpg" height="25">
			多少天内的新添加的文章将会显示<img border="0" src="../images/new.gif" width="28" height="11">。</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			评论显示正文下面</td>
			<td bgcolor="#F8F8F8" width="350" background="../images/bj3.jpg" height="25">
			&nbsp;<select size="1" name="pl">
			<option value="0" <% if rs("pl")=0 then Response.Write " selected "%>>不显示</option>
			<option value="1" <% if rs("pl")=1 then Response.Write " selected "%>>显示</option>
			</select></td>
			<td bgcolor="#F8F8F8" width="250" background="../images/bj3.jpg" height="25">
			文章评论是否显示在文章正文的下面。</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			显示发表评论表单</td>
			<td bgcolor="#F8F8F8" width="350" background="../images/bj3.jpg" height="25">
			&nbsp;<select size="1" name="plfb">
			<option value="1" <% if rs("plfb")=1 then Response.Write " selected "%>>显示</option>
			<option value="0" <% if rs("plfb")=0 then Response.Write " selected "%>>不显示</option>
			</select></td>
			<td bgcolor="#F8F8F8" width="250" background="../images/bj3.jpg" height="25">
			是否在后面显示评论发表的表单。</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			文章列表行距</td>
			<td bgcolor="#F8F8F8" width="350" background="../images/bj3.jpg" height="25">
			&nbsp;<!--webbot bot="Validation" s-display-name="列表行距" s-data-type="Integer" s-number-separators="x" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="3" --><input type="text" value='<%=rs("moreline")%>' name="moreline" size="6" maxlength="3"> 
			pt</td>
			<td bgcolor="#F8F8F8" width="250" background="../images/bj3.jpg" height="25">
			更多文章列表行间距。</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			是否显示搜索条</td>
			<td bgcolor="#F8F8F8" width="350" background="../images/bj3.jpg" height="25">
			&nbsp;<select size="1" name="ggso">
			<option value="1" <% if rs("ggso")=1 then Response.Write " selected "%>>显示</option>
			<option value="0" <% if rs("ggso")=0 then Response.Write " selected "%>>不显示</option>
			</select></td>
			<td bgcolor="#F8F8F8" width="250" background="../images/bj3.jpg" height="25">
			是否在下方显示Google的搜索条，建议显示！</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj6.jpg" height="25">
			IP地址安全过滤</td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj6.jpg" height="25">
			<textarea rows="5" name="ZuZiIP" cols="55"><%=rs("zuziip")%></textarea></td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj6.jpg" height="25">
			　　这里的IP将被阻止访问，用回车分隔。<br>
			不支持通配符*。</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			留言审核</td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			&nbsp;<select size="1" name="lysh">
			<option value="1" <% if rs("lysh")=1 then Response.Write " selected "%>>关闭审核</option>
			<option value="0" <% if rs("lysh")=0 then Response.Write " selected "%>>打开审核</option>
			</select></td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			打开审核后，留言不会立即显示出来！</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			录入员审核</td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			&nbsp;<select size="1" name="lrySH">
			<option value="1" <% if rs("lrySH")=1 then Response.Write " selected "%>>关闭审核</option>
			<option value="0" <% if rs("lrySH")=0 then Response.Write " selected "%>>打开审核</option>
			</select></td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			录入员的文章是否需要管理员审核？</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			评论审核</td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			&nbsp;<select size="1" name="plsh">
			<option value="1" <% if rs("plsh")=1 then Response.Write " selected "%>>关闭审核</option>
			<option value="0" <% if rs("plsh")=0 then Response.Write " selected "%>>打开审核</option>
			</select></td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			游客发布评论是否需要审核才可以显示？</td>
		</tr>
		</table></fieldset></td></tr>
		<tr><td>
		<fieldset style="cursor: default">
		<legend>&nbsp;百度《互联网文章开放协议》索引文件提交</legend>
		
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="TableBorder2">

		<tr>
			<td bgcolor="#F8F8F8" width="732" background="../images/bj6.jpg" height="25" colspan="3">
			　　<a target="_blank" href="../xml-BaiDu.xml">xml-BaiDu.xml</a> 点击打开此文件。如果有此文件并可以正常浏览，你可以点击<a target="_blank" href="http://news.baidu.com/newsop.html#ks5">http://news.baidu.com/newsop.html#ks5</a>进行提交。<br>
			点击<a target="_blank" href="http://news.baidu.com/newsop.html#ks6"><font color="#0000FF">此处</font></a>验证提交的文件是否被通过。</td>
		</tr>
		<tr>
			<td bgcolor="#F8F8F8" width="136" align="center" background="../images/bj3.jpg" height="25">
			站长联系EMAIL</td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			&nbsp;<input type="text" name="WebEmail" value='<%=rs("WebEmail")%>' size="34"></td>
			<td bgcolor="#F8F8F8" width="300" background="../images/bj3.jpg" height="25">
			必填项，百度提交后审核反馈联系用。</td>
		</tr>

		<tr>
			<td bgcolor="#F8F8F8" width="2208" align="center" background="../images/bj3.jpg" height="25" colspan="3">
			<input type="submit" value="提交修改" name="B3">　　<input type="reset" value="重新填写" name="B4"></td>
		</tr>
<%
rs.close
set rs=nothing
%></form></table></fieldset></td></tr></table><center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font></td></tr>
</table></center>