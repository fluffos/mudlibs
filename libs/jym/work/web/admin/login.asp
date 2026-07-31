<html>

<head>

<title>网站后台登录</title>
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
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<meta http-equiv="Content-Language" content="zh-cn">
</head>
		
			
<body topmargin="0" leftmargin="0" rightmargin="0" bottommargin="0" marginwidth="0" marginheight="0" bgcolor="#6D6F71">

<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.user.value = "") Then
    MsgBox "请在 用户名 域中输入值。", 0, "有效性验证错误"
    theForm.user.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.user.value) < 2) Then
    MsgBox "在 用户名 域中，请至少输入 2 个字符。", 0, "有效性验证错误"
    theForm.user.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.user.value) > 20) Then
    MsgBox "在 用户名 域中，请最多输入 20 个字符。", 0, "有效性验证错误"
    theForm.user.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.pass.value = "") Then
    MsgBox "请在 密码 域中输入值。", 0, "有效性验证错误"
    theForm.pass.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.pass.value) < 5) Then
    MsgBox "在 密码 域中，请至少输入 5 个字符。", 0, "有效性验证错误"
    theForm.pass.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.pass.value) > 20) Then
    MsgBox "在 密码 域中，请最多输入 20 个字符。", 0, "有效性验证错误"
    theForm.pass.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.kuang5Yzm.value = "") Then
    MsgBox "请在 验证码 域中输入值。", 0, "有效性验证错误"
    theForm.kuang5Yzm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.kuang5Yzm.value) < 5) Then
    MsgBox "在 验证码 域中，请至少输入 5 个字符。", 0, "有效性验证错误"
    theForm.kuang5Yzm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.kuang5Yzm.value) > 5) Then
    MsgBox "在 验证码 域中，请最多输入 5 个字符。", 0, "有效性验证错误"
    theForm.kuang5Yzm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  checkOK = "0123456789-" 
  checkStr = theForm.kuang5Yzm.value
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
    MsgBox "在 验证码 域中，只能输入 数字 字符。", 0, "有效性验证错误"
    theForm.kuang5Yzm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If ((checkstr <> "" And Not IsNumeric(allNum)) Or (decPoints > 1) Or Not validGroups) Then
    MsgBox "请在 kuang5Yzm 域中输入一个有效数字。", 0, "有效性验证错误"
    theForm.kuang5Yzm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_login.asp" target=_top name="FrontPage_Form1">
<div align="center">
	<table border="0" cellpadding="0" cellspacing="0" width="100%" height="100%" id="table9" >
		<tr>
			<td style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
			<div align="center">
				<table border="0" cellpadding="0" cellspacing="0"  background="images/kuang5_login.jpg" width="563" height="364" id="table10">
					<tr>
						<td valign="top" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
						<div align="center">
							<div align="center">
								<table border="0" cellpadding="0" cellspacing="0" width="100%" id="table11">
									<tr>
										<td width="207" height="130" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
										<td height="130" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">			<%
			if request("id")="0" then response.write "请填写完整！"
			if request("id")="1" then response.write "用户名或密码错误！"
			if request("id")="3" then response.write "验证码错误"
			if request("id")="8" then response.write "网络超时，或未登录。请重新登录！"
			if request("id")="9" then response.write "正常退出后台管理系统"
			%>
			</td>
										<td width="37" height="130" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
									</tr>
									<tr>
										<td width="207" height="111" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
										<td height="111" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
										
										<table border="0" cellpadding="5" cellspacing="0" width="319" id="table12">
											<tr>
												<td width="114" align="center" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
												用户名</td>
												<td width="205" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
												<!--webbot bot="Validation" s-display-name="用户名" b-value-required="TRUE" i-minimum-length="2" i-maximum-length="20" --><input type="text" name="user" size="24" maxlength="20" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000"></td>
											</tr>
											<tr>
												<td width="114" align="center" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
												密　码</td>
												<td width="205" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
												<!--webbot bot="Validation" s-display-name="密码" b-value-required="TRUE" i-minimum-length="5" i-maximum-length="20" --><input type="password" name="pass" size="24" maxlength="20" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000"></td>
											</tr>
											<tr>
												<td width="114" align="center" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
												验证码</td>
												<td width="205" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
												<!--webbot bot="Validation" s-display-name="验证码" s-data-type="Integer" s-number-separators="x" b-value-required="TRUE" i-minimum-length="5" i-maximum-length="5" --><input name="kuang5Yzm" size="9" maxlength="5" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000">
												<%
												Randomize
												an=""
												an= int((99999-11111+1) * RND +11111)
												session("kuang5yzm")=an
												Response.Write an
												%>
												</td>
											</tr>
											</table>
										</td>
										<td width="37" height="111" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
									</tr>
									<tr>
										<td width="207" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
										<td style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
										<td width="37" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
									</tr>
									<tr>
										<td width="207" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
										<td style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">
										<p align="center">
											<input type="submit" value=" 登 陆 " name="B1">&nbsp;&nbsp;
											<input type="button" onClick="javascript:window.opener=null;window.close()" value=" 关 闭 "></td>
										<td width="37" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
									</tr>
									<tr>
										<td width="207" height="56" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
										<td height="56" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
										<td width="37" height="56" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
									</tr>
									<tr>
										<td width="207" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">&nbsp;　<font color="#FFBEC6"><%=year(now())&"-"&Month(now())&"-"&day(now())&" "&hour(time())&":"&Minute(now())&":"&Second(now())%></font></td>
										<td style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all"><span style="letter-spacing: -1pt">　　　　　　</span>　&nbsp;<a target="_blank" href="http://www.kuang5.com" ><font color="#FFBEC6">狂舞游戏网站系统　 &nbsp;<a target="_blank" style="text-decoration:underline" href="http://www.kuang5.com" ><font color="#FFBEC6">Www.Kuang5.Com</font></a></td>
										<td width="37" style="font-size: 9pt; font-family: 宋体,MingLiU, Arial; color: #000000; table-layout: fixed; word-break: break-all">　</td>
									</tr>
								</table>
							</div>
						</div>
						</td>
					</tr>
				</table>
			</div>
			</td>
		</tr>
	</table>
</div>
</form>

</body>

</html>