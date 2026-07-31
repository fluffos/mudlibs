<!--#include file = kuang5_conn.asp -->
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
<title>查看评论</title>
<%
id=trim(request("id"))
action=trim(request("action"))
editcontent=trim(request("editcontent"))

if action="save" and id<>"" and editcontent<>"" then
	conn.Execute "update [newspl] set [content]='"&editcontent&"' where id="&clng(id)
end if

sql = "select * from newspl where id="&clng(ID)
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1

content=rs("content")

rs.close
set rs=nothing
conn.close
set conn=nothing
%><div align="center">
	<table border="0" cellpadding="20" cellspacing="0" width="100%" id="table1" height="100%">
		<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.editcontent.value = "") Then
    MsgBox "请在 评论内容 域中输入值。", 0, "有效性验证错误"
    theForm.editcontent.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.editcontent.value) < 1) Then
    MsgBox "在 评论内容 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.editcontent.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_news_pl_view.asp?action=save&id=<%=id%>" name="FrontPage_Form1">
<tr>
			<td align=center>
				&nbsp;<!--webbot bot="Validation" s-display-name="评论内容" b-value-required="TRUE" i-minimum-length="1" --><textarea rows="10" name="editcontent" cols="68"><%=content%></textarea><br>
				<input type="submit" value="　　修改保存　　" name="B1">
			
			</td>
		</tr></form>
	</table>
</div>