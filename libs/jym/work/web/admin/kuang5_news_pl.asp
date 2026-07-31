<%
if Request.Cookies("admindj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
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
<link rel="stylesheet" type="text/css" href="admin_style.css">
</head>

<%
sh=trim(request("sh"))
shid=trim(request("shid"))
delid=trim(request("delid"))

if delid<>"" then
	conn.Execute "delete from [newspl] where ID="&clng(delid)
end if	

if sh<>"" and shid<>"" then
	conn.Execute "update [newspl] set [sh]="&sh&" where id="&clng(shid)
end if
%>
<body>


	<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.word.value = "") Then
    MsgBox "请在 关键字 域中输入值。", 0, "有效性验证错误"
    theForm.word.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.word.value) < 1) Then
    MsgBox "在 关键字 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.word.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.word.value) > 20) Then
    MsgBox "在 关键字 域中，请最多输入 20 个字符。", 0, "有效性验证错误"
    theForm.word.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="<%=request.servervariables("URL")%>" name="FrontPage_Form1"><tr>
			<th colspan="2">
				查看评论</th>
		</tr><tr>
			<td width="151" class="TableRow"><img border=0 src="images/s.gif" align=absmiddle><a href="kuang5_news_pl.asp">评论管理</a>&nbsp;</td><td class="TableRow">
				<p align="center">
				&nbsp;<!--webbot bot="Validation" s-display-name="关键字" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="20" --><input type="text" name="word" size="20" maxlength="20">　　<select size="1" name="zd">
				<option value="content">内容</option>
				<option value="username">作者</option>
				</select>　　<input type="submit" value="搜索评论" name="B1"></p>
			</td>
		</tr></form>
	</table>

<table border=0><tr><td height=3></td></tr></table>

<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th width="409" align="center">
			<font color="#FFFFFF">作者　内容</font></td>
			<th width="164" align="center">
			<font color="#FFFFFF">发布时间　IP</font></td>
			<th width="182" align="center">
			<font color="#FFFFFF">相关操作</font></td>
		</tr>
		<%
		word=trim(request("word"))
		zd=trim(request("zd"))
		sql = "select * from newspl order by id desc"
		if word<>"" and zd<>"" then sql = "select * from newspl where "&zd&" like '%"&word&"%' order by id desc"
		Set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open sql,conn,1,1
		
		if rs.recordcount<>0 then
		
		page=int(request("page"))
		rs.PageSize=10
		pagecount=rs.pagesize
		if page<=0 then page=1
		if request("page")="" then page=1
		rs.AbsolutePage=page
		for i=1 to pagecount
		%>
		<tr>
			<td width="409" class="TableRow"><font color="#0066CC"><%=rs("username")%></font><br>
		  <a href=# onclick='window.open("kuang5_news_pl_view.asp?id=<%=rs("id")%>","newsplview","width=480,height=200,top=70,left=150,scrollbars=no" )'><%=titleb(rs("content"),66)%></a></td>
			<td width="164" class="TableRow"><a href=# onclick='window.open("kuang5_ip.asp?iP=<%=rs("ip")%>","newsplview","width=380,height=200,top=190,left=150,scrollbars=no" )'><%=rs("IP")%>(查看来源)</a><br><%=rs("addtime")%></td>
			<td width="182" class="TableRow">
			<p align="center">
			<a target="_blank" href="../news_view.asp?newsid=<%=rs("newsid")%>">相关文章</a> <a href="../NewsPL.asp?id=<%=rs("newsid")%>" target=_blank>相关评论</a><br>
		  <%
			if rs("sh")="0" then 
				Response.Write "<a href=?sh=1&shid="&rs("id")&"&page="&page&">未审核</a>"
			else
				Response.Write "<a href=?sh=0&shid="&rs("id")&"&page="&page&">已审核</a>"
			end if
			%>&nbsp;<a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href="?delid=<%=rs("id")%>">删除评论</a></td>
		</tr>
		<%
		rs.movenext 
		if rs.eof then exit for
		next
		else 
		  Response.Write "<tr><td colspan=3>暂无信息</td></tr>"
		end if
		%>
		<tr class=trp>
<td colspan=4 class=tablerow1>
  <div align="center">
   <table border="0" cellpadding="0" cellspacing="1" align="right" class="Tableborder5">
      <tr>
        <td class="tabletitle1"><center>&nbsp;
          <%if rs.recordcount<>0 then
  if page>1 then
    response.write "<a href="&request.servervariables("URL")&"?page=1>首页</a>　"
    response.write "<a href="&request.servervariables("URL")&"?page="&page-1&">上一页</a>　"
  end if
  if page<rs.pagecount then
    response.write "<a href="&request.servervariables("URL")&"?page="&page+1&">下一页</a>　"
    response.write "<a href="&request.servervariables("URL")&"?page="&rs.pagecount&">尾页</a>　"
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
          <select class="sel" size="1" onChange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="font-size: 9pt; border-style: solid; border-width: 1px">
            <%for i=1 to rs.pagecount%>
            <option value="<%=request.servervariables("URL")%>?page=<%=i%>" <%if page=i then response.write "selected"%> style="font-size: 9pt">第<%=i%>页</option>
            <%next%>
            </select>
          <%end if%>
          </center></td>
        </tr>
    </table>
  </div></td>
</tr>
	</table>
	<center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
</table></center>

