

<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<style>
<!--
a:link       { font-size: 9pt; font-family: 宋体; color: #000000;text-decoration: none; }
a:visited    { color: #000000; font-family: 宋体; font-size: 9pt;text-decoration: none; }
a:hover      { font-size: 9pt; font-family: 宋体; color: #000000;TEXT-DECORATION: underline; }
body         { font-family: 宋体; color: #000000; font-size: 9pt }
p            { color: #000000; font-family: 宋体; font-size: 9pt }
td           { font-size: 9pt; font-family: 宋体; color: #000000 }
input        { font-size: 9pt; font-family: 宋体; color: #000000 }

-->
</style>
<head>
<!--#include file = language.asp -->
</head>

<%
id=trim(request("id"))
if id<>"" then
sql = "select * from admin where id="&id
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
if rs.recordcount<>0 then
  username=rs("user")
end if
rs.close
set rs=nothing

end if
%>
<p align="center"><br>
<a href=javascript:history.back();>返回</a><br>
　</p>
<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.username.value = "") Then
    MsgBox "请在 用户名 域中输入值。", 0, "有效性验证错误"
    theForm.username.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.username.value) < 2) Then
    MsgBox "在 用户名 域中，请至少输入 2 个字符。", 0, "有效性验证错误"
    theForm.username.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.username.value) > 20) Then
    MsgBox "在 用户名 域中，请最多输入 20 个字符。", 0, "有效性验证错误"
    theForm.username.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.password.value = "") Then
    MsgBox "请在 密码 域中输入值。", 0, "有效性验证错误"
    theForm.password.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.password.value) < 6) Then
    MsgBox "在 密码 域中，请至少输入 6 个字符。", 0, "有效性验证错误"
    theForm.password.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.password.value) > 20) Then
    MsgBox "在 密码 域中，请最多输入 20 个字符。", 0, "有效性验证错误"
    theForm.password.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_admin_editpass_save.asp?id=<%=id%>" name="FrontPage_Form1">
	<div align="center">
		<table border="1" width="80%" id="table1" cellspacing="0" cellpadding="6" style="border-collapse: collapse" bordercolor="#C0C0C0">
			<tr>
				<td align="center" bgcolor="#C0C0C0" colspan="2">
				<p align="left"><font face="Wingdings">1</font><b>修改<%=username%>密码</b></td>
			</tr>
			<tr>
				<td width="100" align="center">用户名</td>
				<td>
				&nbsp;<!--webbot bot="Validation" S-Display-Name="用户名" B-Value-Required="TRUE" I-Minimum-Length="2" I-Maximum-Length="20" --><input type="text" name="username" size="42" value="<%=username%>" maxlength="20"></td>
			</tr>
			<tr>
				<td width="100" align="center">密　码</td>
				<td>
				&nbsp;<!--webbot bot="Validation" s-display-name="密码" b-value-required="TRUE" i-minimum-length="6" i-maximum-length="20" --><input type="text" name="password" size="42" maxlength="20"></td>
			</tr>
	  </table>
	</div>
	<p align="center"><input type="submit" value=" 提 交 " name="B1">&nbsp;<input type="reset" value=" 重 置 " name="B2"></p>
</form>
<p align="center">　</p>