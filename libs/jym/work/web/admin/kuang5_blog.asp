<%
'ON ERROR RESUME NEXT
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp --><head>
<meta http-equiv="Content-Language" content="zh-cn">
<link rel="stylesheet" type="text/css" href="admin_style.css">
</head>









<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
		
			<th height="25" width="163" align="center">
			<font color="#FFFFFF">时间</font></th>
			<th height="25" width="576" align="center">
			<font color="#FFFFFF">事件</font></td>
		</tr>
		<tr>
			<td>
			<p align="center"><a href="?delid=all" onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}'><strong>清除全部日志</strong></a></td>
		</tr>
<%

delid=trim(Request("delid"))

if delid="all" then
	addtime=date()
	conn.Execute "delete from [blog] "
end if

conn.Execute "delete from [blog] where datediff('d',addtime,now())>30 "
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [blog] order by id desc",conn,1,1
if rs.recordcount<>0 then

page=int(request("page"))
rs.PageSize=20
pagecount=rs.pagesize
if page<=0 then page=1
if request("page")="" then page=1
rs.AbsolutePage=page

for i=0 to pagecount
%>
		<tr>
			<td class=TableRow width="163" align=center><%=rs("addtime")%></td>
			<td class=TableRow width="576"><%=rs("content")%></td>
		</tr>
<%
rs.movenext
if rs.eof then exit for
next
end if

%>
<tr><td class=TableRow colspan="2"><div align="right">	  <table border="0" cellpadding="0" cellspacing="1" align="right" class="Tableborder5"><tr><td class="tabletitle1">
  <%if rs.recordcount<>0 then
if page>1 then
response.write "<a href="&request.servervariables("URL")&"?page=1&id="&id&"&word="&word&"&lm="&lm&">首页</a>　"
response.write "<a href="&request.servervariables("URL")&"?page="&page-1&"&id="&id&"&word="&word&"&lm="&lm&">上一页</a>　"
end if
if page<rs.pagecount then
response.write "<a href="&request.servervariables("URL")&"?page="&page+1&"&id="&id&"&word="&word&"&lm="&lm&">下一页</a>　"
response.write "<a href="&request.servervariables("URL")&"?page="&rs.pagecount&"&id="&id&"&word="&word&"&lm="&lm&">尾页</a>　"
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

        <select size="1" onchange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="font-size: 9pt; border-style: solid; border-width: 1px">
          <%for i=1 to rs.pagecount%>
          <option value="<%=request.servervariables("URL")%>?page=<%=i%>&id=<%=id%>&word=<%=word%>&lm=<%=lm%>" <%if page=i then response.write "selected"%> style="font-size: 9pt">第<%=i%>页</option>
          <%next%>
        </select>
        <%end if%>
</td></tr></table></td></tr>
	</table>


<%
conn.close:set conn=nothing
%>