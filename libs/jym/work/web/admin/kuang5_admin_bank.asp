<%
if Request.Cookies("admindj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->

<head>
<!--#include file = language.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
</head>
<body>


<%
if trim(request("bank"))<>"" then
	 'conn.Execute "update [config] set bank='"&trim(request("bank"))&"',tgbottom='"&trim(request("tgbottom"))&"'"
	 set rs = Server.CreateObject("ADODB.RecordSet")
	 rs.Open "select * from [config] order by id desc",conn,1,3
	 rs("bank")=trim(request("bank"))
	 rs.update
	 response.Write("<script language=javascript>")
	 response.Write("alert('保存成功');")
	 response.Write("</script>")
end if

Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [config]",conn,1,1
bank=rs("bank")
rs.close
set rs=nothing
%>


<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.bank.value = "") Then
    MsgBox "请在 汇款方式 域中输入值。", 0, "有效性验证错误"
    theForm.bank.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.bank.value) < 1) Then
    MsgBox "在 汇款方式 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.bank.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_admin_bank.asp" name="FrontPage_Form1">
		<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		  <tr>
    <th align="left" colspan="2">&nbsp;汇款方式修改</th>
  </tr>
			<tr><td width="8%" class="TableRow1">汇款方式:</td>
				<td width="92%" align="center" class="TableRow1">
<textarea name="bank" style="display:none"><%=bank%></textarea>
<iframe ID="eWebEditor1" src="../edit/ewebeditor.htm?id=bank&style=coolblue" frameborder="5" scrolling="no" width="100%" HEIGHT="500"></iframe>
			  </td>
			</tr>
		<tr>
		<td colspan="2" class="TableRow1" align="center">
	<input type="submit" value="保存修改" name="B1">　　　<input type="reset" value="重新填写" name="B2"></td></tr>
		</table>
<center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
</table></center>
</form>
<%
conn.close
set conn=nothing
%>