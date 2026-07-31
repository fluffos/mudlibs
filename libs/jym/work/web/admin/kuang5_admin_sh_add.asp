

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
  lmid=rs("lmid")
end if
rs.close
set rs=nothing

end if
%>

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

  If (Len(theForm.username.value) > 10) Then
    MsgBox "在 用户名 域中，请最多输入 10 个字符。", 0, "有效性验证错误"
    theForm.username.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_admin_sh_add_save.asp?id=<%=id%>" name="FrontPage_Form1">
	<div align="center">
		　<p>　</p>
		<table border="1" width="600" id="table1" cellspacing="0" cellpadding="7" style="border-collapse: collapse" bordercolor="#C0C0C0">
			<tr>
				<td width="127" align="center">用户名</td>
				<td>
				&nbsp;<!--webbot bot="Validation" s-display-name="用户名" b-value-required="TRUE" i-minimum-length="2" i-maximum-length="10" --><input type="text" value="<%=username%>" name="username" size="36" maxlength="10"></td>
			</tr>
			<tr>
				<td width="127" align="center">密　码</td>
				<td>
				&nbsp;<input type="text" name="password" size="36" maxlength="20"></td>
			</tr>
			<tr>
				<td width="127" align="center">二级栏目权限<br>(仅添加文章时有效)</td>
				<td>
				<%
				sql = "select * from lm where lm<>''"
				Set rs = Server.CreateObject("ADODB.RecordSet")
				rs.Open sql,conn,1,1
				while not rs.eof
				    response.write "<input type=checkbox name=lmid value="&rs("id")&" id="&rs("id")&"><label for="&rs("id")&"><B>"&rs("lm")&"</b><font color=999999>(编号:"&rs("id")&")</font></label><BR>"
				    '	"<BR><B>"&rs("lm")&"<font color=999999>(编号:"&rs("id")&")</font></b><br>"
				    sql2 = "select * from lm where lmid='"&rs("id")&"'"
				    Set rs2 = Server.CreateObject("ADODB.RecordSet")
				    rs2.Open sql2,conn,1,1
				    while not rs2.eof
				        Response.Write "　 <input type=checkbox name=lmid value="&rs2("id")&" id="&rs2("id")&"><label for="&rs2("id")&">"&rs2("lm2")&"<font color=999999>(编号:"&rs2("id")&")</font></label><BR>"
				        Set rs33 = Server.CreateObject("ADODB.RecordSet")
				        rs33.Open "select * from [lm] where lmid='"&rs2("id")&"' and LM3<>'' order by id desc",conn,1,1
				        while not rs33.eof
				           Response.Write "　　　 <input type=checkbox name=lmid value="&rs33("id")&" id="&rs33("id")&"><label for="&rs33("id")&">"&rs33("lm3")&"<font color=999999>(编号:"&rs33("id")&")</font></label><BR>"
				        rs33.movenext
				        wend
				    rs2.movenext
					wend
				rs.movenext
				wend
				%>
				</td>
			</tr>
			</table>
	</div>
	<p align="center"><input type="submit" value="提交" name="B1">　　　<input type="reset" value="重置" name="B2"></p>
</form>