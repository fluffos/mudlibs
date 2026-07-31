<%
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
<script language="JavaScript">

 var msg  = "欢迎使用狂舞游戏网站系统    " ;

var interval = 120

var spacelen = 120;

var space10=" ";

var seq=0;

function Scroll() {

len = msg.length;

window.status = msg.substring(0, seq+1);

seq++;

if ( seq >= len ) { 

seq = 0; 

window.status = '';

window.setTimeout("Scroll();", interval );

}

else

window.setTimeout("Scroll();", interval );

} 

Scroll();

</script>
<!--#include file = language.asp -->
<title> </title>
<link rel="stylesheet" type="text/css" href="admin_style.css">
</head>

<body>

<%
if request("edit")="1" and request("id")<>"" then
  sql = "select * from link where id="&request("ID")
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
end if
%>
			<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.linkname.value = "") Then
    MsgBox "请在 网站名称 域中输入值。", 0, "有效性验证错误"
    theForm.linkname.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.linkname.value) < 1) Then
    MsgBox "在 网站名称 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.linkname.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.linkname.value) > 255) Then
    MsgBox "在 网站名称 域中，请最多输入 255 个字符。", 0, "有效性验证错误"
    theForm.linkname.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.url.value = "") Then
    MsgBox "请在 网站地址 域中输入值。", 0, "有效性验证错误"
    theForm.url.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.url.value) < 10) Then
    MsgBox "在 网站地址 域中，请至少输入 10 个字符。", 0, "有效性验证错误"
    theForm.url.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_link_add_save.asp<%if request("edit")="1" then response.write "?id="&rs("id")%>" name="FrontPage_Form1">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
					<tr>
						<th align="left" colspan="2">&nbsp;添加/修改友情链接</th>
					</tr>
					<tr>
						<td class=TableRow width="98" align="center">网站名称</td>
						<td class=TableRow>
						&nbsp;<!--webbot bot="Validation" s-display-name="网站名称" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="255" --><input type="text" name="linkname" size="31" <%
						if request("edit")=1 then 
						response.write "value='"&rs("linkname")&"'"
						end if
						%> maxlength="255"></td>
					</tr>
					<tr>
						<td class=TableRow width="98" align="center">网站地址</td>
						<td class=TableRow>
						&nbsp;<!--webbot bot="Validation" s-display-name="网站地址" b-value-required="TRUE" i-minimum-length="10" --><input type="text" name="url" size="42" <%
						if request("edit")=1 then
						  response.write "value="&rs("url")
						 else
						  response.write "value=http://" 
						end if
						%>></td>
					</tr>
					<tr>
						<td class=TableRow width="98" align="center">网站LOGO</td>
						<td class=TableRow>
						&nbsp;<input type="text" name="logo" size="52" <%
						if request("edit")=1 then
						  response.write "value="&rs("logo")
						 else
						  response.write "value=" 
						end if
						%>> 图片　宽:88　高:31</td>
					</tr>
					<tr>
						<td class=TableRow width="98" align="center">网站介绍</td>
						<td class=TableRow>
						&nbsp;<input type="text" name="js" size="52" <%
						if request("edit")=1 then
						  response.write "value="&rs("js")
						 else
						  response.write "value=" 
						end if
						%>></td>
					</tr>
					<tr>
						<td class=TableRow align="center" colspan="2"><input type="submit" value="保存修改" name="B1">　　　<input type="reset" value="重新填写" name="B2"></td>
					</tr>
				</table>
			</form>


<%
id=trim(request("id"))
ontop=trim(request("ontop"))
upd=trim(request("upd"))
addtime=date()

if ontop<>"" then
  conn.Execute "update [link] set ontop="&ontop&" where id="&clng(id)
elseif upd<>"" then
  conn.Execute "update [link] set upd='"&addtime&"' where id="&clng(upd)
end if
  sql = "select * from link order by ontop desc , upd desc , id desc"
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
  
%>

<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th><b>LOGO</b></th>
			<th><b>网站名称</b></th>
			<th><b>网站地址</b></th>
			<th><b>操　作</b></th>
		</tr>
<%
if rs.recordcount<>0 then

page=int(request.QueryString ("page"))
rs.PageSize=20
pagecount=rs.pagesize
if page<=0 then page=1
if request.QueryString("page")="" then page=1
rs.AbsolutePage=page
   for i=0 to pagecount
     ontop=rs("ontop")
     if ontop="" then ontop=3
     if ontop="3" then 
       ontop=5
     else
       ontop=3
     end if
%>
		<tr>
			<td class=TableRow width="103" align=center style="table-layout:fixed;word-break:break-all" height="25">
			<%
			if trim(rs("logo"))<>"" then
			   response.write "<a href="&rs("url")&" target=_blank title='"&rs("js")&"'><img border=0 width=88 height=31 src=" & rs("logo") & "></a>"
			end if
			%></td>
			<td class=TableRow width="148" height="25" align=center><a href="<%=rs("url")%>" target=_blank>
<%=rs("linkname")%></a></td>
			<td class=TableRow width="180" style="table-layout:fixed;word-break:break-all" height="25"><%if rs("ontop")="5" then Response.Write "<b><font color=blue>[顶]</font></b>"%><a href="<%=rs("url")%>" target=_blank title='<%=rs("url")%>'><%=titleb(rs("url"),23)%></a></td>
			<td class=TableRow width="138" height="25">
			<p align="center"><a href="kuang5_link.asp?id=<%=rs("id")%>&edit=1">修改</a>　<a href=kuang5_link.asp?ontop=<%=ontop%>&id=<%=rs("id")%>>固顶</a>　<a href=kuang5_link.asp?upd=<%=rs("id")%>>提升</a>　<a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href="kuang5_link_del.asp?id=<%=rs("id")%>">删除</a></td>
		</tr>
<%
 rs.movenext
 if rs.eof then exit for
 next

end if
%><tr><td colspan="4" class=tablerow1><table border="0" cellpadding="0" cellspacing="1" align="right" class="Tableborder5">
  <tr><td class="tabletitle1"><%if rs.recordcount<>0 then
  if page>1 then
    response.write "<a href="&request.servervariables("URL")&"?page=1>首页</a>　"
    response.write "<a href="&request.servervariables("URL")&"?page="&page-1&">上一页</a>　"
  end if
  if page<rs.pagecount then
    response.write "<a href="&request.servervariables("URL")&"?page="&page+1&">下一页</a>　"
    response.write "<a href="&request.servervariables("URL")&"?page="&rs.pagecount&">尾页</a>　"
  end if
    response.write "&nbsp;共"&rs.recordcount&"条　每页显示"&pagecount&"条　共"&rs.pagecount&"页　"
  %>
  <script language="JavaScript">
  <!--
  function FP_jumpMenu(el,frm,sel) {//v1.0
    var href=el.options[el.selectedIndex].value; if(sel) el.selectedIndex=0;
    if('_new'==frm) open(href); else eval(frm+".location='"+href+"'");
    }
    // -->
  </script>
  <select size="1" onChange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="font-size: 9pt; border-style: solid; border-width: 1px">
   <%for i=1 to rs.pagecount%>
   <option value="<%=request.servervariables("URL")%>?page=<%=i%>" <%if page=i then response.write "selected"%>>第<%=i%>页</option>
    <%next%>
   </select>
<%end if%></td></tr></table></td></tr>
	</table>
<center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
</table></center>
</body>
<%
conn.close
set conn=nothing
%>
</html>