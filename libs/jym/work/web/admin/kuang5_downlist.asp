<%
if session("dj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<head>
<!--#include file = language.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
</head>
<body>
<%

Function finddir(filepath)
	finddir=""
	for i=1 to len(filepath)
	if left(right(filepath,i),1)="/" or left(right(filepath,i),1)="\" then
	  abc=i
	  exit for
	end if
	next
	if abc <> 1 then
	finddir=left(filepath,len(filepath)-abc+1)
	end if
end Function

editid=trim(Request("editid"))
saveid=trim(Request("saveid"))
delid=trim(Request("delid"))
downname=Request("downname")
downsize=Request("downsize")
pic=Request("pic")
sm=Request("sm")
dz1=Request("dz1")
dz2=Request("dz2")
addtime=date()

if editid<>"" and trim(Request("downname"))="" and trim(Request("downsize"))="" and trim(Request("pic"))="" and trim(Request("sm"))="" and trim(Request("dz1"))="" and trim(Request("dz2"))="" then
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open "select * from [downlist] where id="&clng(editid),conn,1,1
  if rs.recordcount<>0 then
     editdownname=rs("downname")
     editdownsize=rs("downsize")
     editpic=rs("pic")
     editsm=rs("sm")
	 editdz1=rs("dz1")
	 editdz2=rs("dz2")
	 editaddtime=rs("addtime")
  end if
  rs.close
  set rs=nothing
elseif saveid="" and trim(Request("downname"))<>"" and trim(Request("downsize"))<>"" and trim(Request("pic"))<>"" and trim(Request("sm"))<>"" and trim(Request("dz1"))<>"" and trim(Request("dz2"))<>"" then
     conn.Execute "insert into [downlist] ([downname],[downsize],[pic],[sm],[dz1],[dz2],[addtime]) values('"&downname&"','"&downsize&"','"&pic&"','"&sm&"','"&dz1&"','"&dz2&"','"&addtime&"')"   
     Response.Redirect "kuang5_downlist.asp"
elseif saveid<>"" and trim(Request("downname"))<>"" and trim(Request("downsize"))<>"" and trim(Request("pic"))<>"" and trim(Request("sm"))<>"" and trim(Request("dz1"))<>"" and trim(Request("dz2"))<>"" then
   conn.Execute "update [downlist] set downname='"&downname&"',downsize='"&downsize&"',pic='"&pic&"',sm='"&sm&"',dz1='"&dz1&"',dz2='"&dz2&"',addtime='"&addtime&"' where id="&clng(saveid)
   Response.Redirect "kuang5_downlist.asp"
elseif delid<>"" then
   conn.Execute "delete from [downlist] where ID="&CInt(delid)
end if
%>
	<div align="center">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th width="152">软件名称</th>
			<th width="108">软件图片</th>
			<th width="53">软件大小</th>
			<th width="158">软件说明</th>
			<th width="101">下载地址一</th>
			<th width="98">下载地址二</th>
			<th width="65">
			  <strong><font color="#FFFFFF">操　作</font></strong></td>		</th>
		<%
		Set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [downlist] order by id desc",conn,1,1
		
		if rs.recordcount<>0 then
		
		page=int(request("page"))
		rs.PageSize=10
		pagecount=rs.pagesize
		if page<=0 then page=1
		if request("page")="" then page=1
		rs.AbsolutePage=page
		
		for k=1 to pagecount
		%>
		<tr>
			<td class=tablerow1 width="152"><font color="#666666">(编号:<%=rs("id")%>)</font><%=rs("downname")%><br></td>
			<td class=tablerow1 width="108"><img src="<%=rs("pic")%>"></td>
			<td class=tablerow1 width="53"><%=rs("downsize")%></td>
			<td class=tablerow1 width="158"><%=rs("sm")%></td>
			<td class=tablerow1 width="101"><%=rs("dz1")%></td>
			<td class=tablerow1 width="98"><%=rs("dz2")%></td>
			<td class=tablerow1 width="65" align="center">
		  <p align="center"><a href="kuang5_downlist.asp?editid=<%=rs("ID")%>">修改</a>　<a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href="kuang5_downlist.asp?delid=<%=rs("id")%>">删除</a></td>
		</tr>
		<%
		rs.movenext
		if rs.eof then exit for
		next
		else
		  Response.Write "<tr class='tr'><td colspan=2>暂无游戏开区信息</td></tr>"
		end if
		
		%>
<tr>
<td class=tablerow1 colspan=7>
<table border="0" cellpadding="0" cellspacing="1" align="right" class="Tableborder5">
    <tr>
      
    <td class="tabletitle1">&nbsp;
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
  <select size="1" onChange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="border: 1px solid #c0c0c0; padding: 1px; background-color: #ededed;">
   <%for i=1 to rs.pagecount%>
   <option value="<%=request.servervariables("URL")%>?page=<%=i%>" <%if page=i then response.write "selected"%> style="font-size: 9pt">第<%=i%>页</option>
    <%next%>
   </select>
<%end if%>
</center></td>
    </tr>
  </table>
</td>
</tr>
  </table>
				<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan -->
				<script Language="JavaScript" Type="text/javascript"><!--
function FrontPage_Form1_Validator(theForm)
{

  if (theForm.downname.value == "")
  {
    alert("请在 软件名称标题 域中输入值。");
    theForm.downname.focus();
    return (false);
  }

  if (theForm.downname.value.length < 1)
  {
    alert("在 软件名称标题 域中，请至少输入 1 个字符。");
    theForm.downname.focus();
    return (false);
  }

  if (theForm.downname.value.length > 90)
  {
    alert("在 软件名称标题 域中，请最多输入 20 个字符。");
    theForm.downname.focus();
    return (false);
  }

  if (theForm.downsize.value == "")
  {
    alert("请在 软件大小 域中输入值。");
    theForm.downsize.focus();
    return (false);
  }

  if (theForm.downsize.value.length < 1)
  {
    alert("在 软件大小 域中，请至少输入 1 个字符。");
    theForm.downsize.focus();
    return (false);
  }

  if (theForm.downsize.value.length > 90)
  {
    alert("在 软件大小 域中，请最多输入 20 个字符。");
    theForm.downsize.focus();
    return (false);
  }
  
    if (theForm.pic.value == "")
  {
    alert("请在 软件图片 域中输入值。");
    theForm.pic.focus();
    return (false);
  }

  if (theForm.pic.value.length < 1)
  {
    alert("在 软件图片 域中，请至少输入 1 个字符。");
    theForm.pic.focus();
    return (false);
  }

  if (theForm.pic.value.length > 90)
  {
    alert("在 软件图片 域中，请最多输入 20 个字符。");
    theForm.pic.focus();
    return (false);
  }
  
      if (theForm.sm.value == "")
  {
    alert("请在 软件说明 域中输入值。");
    theForm.sm.focus();
    return (false);
  }

  if (theForm.sm.value.length < 1)
  {
    alert("在 软件说明 域中，请至少输入 1 个字符。");
    theForm.sm.focus();
    return (false);
  }

  if (theForm.sm.value.length > 90)
  {
    alert("在 软件说明 域中，请最多输入 200 个字符。");
    theForm.sm.focus();
    return (false);
  }
  
        if (theForm.dz1.value == "")
  {
    alert("请在 下载地址一 域中输入值。");
    theForm.dz1.focus();
    return (false);
  }

  if (theForm.dz1.value.length < 1)
  {
    alert("在 下载地址一 域中，请至少输入 1 个字符。");
    theForm.dz1.focus();
    return (false);
  }

  if (theForm.dz1.value.length > 90)
  {
    alert("在 下载地址一 域中，请最多输入 200 个字符。");
    theForm.dz1.focus();
    return (false);
  }
          if (theForm.dz2.value == "")
  {
    alert("请在 下载地址二 域中输入值。");
    theForm.dz2.focus();
    return (false);
  }

  if (theForm.dz2.value.length < 1)
  {
    alert("在 下载地址二 域中，请至少输入 1 个字符。");
    theForm.dz2.focus();
    return (false);
  }

  if (theForm.dz2.value.length > 90)
  {
    alert("在 下载地址二 域中，请最多输入 200 个字符。");
    theForm.dz2.focus();
    return (false);
  }
  return (true);
}
//--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_downlist.asp?saveid=<%=editid%>" onSubmit="return FrontPage_Form1_Validator(this)" language="JavaScript" name="FrontPage_Form1">
					<div align="center">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
							<tr>
							  <th colspan="2" align="left">&nbsp;添加/修改游戏下载</th>
						  </tr>
							<tr>
							  <td class="TableRow1" width="156" align="center""><div align="right">软件名称：</div></td>
								<td class="TableRow1" width="589"><div align="left">
							    <!--webbot bot="Validation" s-display-name="软件名称标题" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="200" -->
							    <input type="text" class="txt"name="downname" size="30" value="<%=editdownname%>" maxlength="100">
						      </div></td>
							</tr>
							
<tr>
		  <td class="TableRow1" width="156" align="center"><div align="right">软件图片：</div></td>
								<td class="TableRow1" width="589">
								  <input name="pic" type="text" class="txt"value="<%=editpic%>" size="30" maxlength="200">
		  &nbsp;<!--webbot bot="Validation" s-display-name="软件图片" b-value-required="TRUE" i-minimum-length="200" --></td>
	    </tr>
<tr>
					  <td class=TableRow align="right">软件图片上传:</td>
			  <td class=TableRow><iframe name="ad" frameborder=0 width=100% height=23 scrolling=no src="../edit/sitedde43vc125jve4g45f.asp"></iframe></td>
	</tr>
<tr>
							  <td class="TableRow1" width="156" align="center"><div align="right">软件大小：</div></td>
							  <td class="TableRow1" width="589">
								  <input name="downsize" type="text" class="txt"value="<%=editdownsize%>" size="30" maxlength="200">
							  &nbsp;<!--webbot bot="Validation" s-display-name="软件名称内容ＩＰ" b-value-required="TRUE" i-minimum-length="200" --></td>
							</tr>
<tr>
		  <td class="TableRow1" width="156" align="center"><div align="right">软件说明：</div></td>
								<td class="TableRow1" width="589">
						<textarea name="sm" cols="50" rows="3"><%=editsm%></textarea>
		  &nbsp;<!--webbot bot="Validation" s-display-name="软件名称状态" b-value-required="TRUE" i-minimum-length="200" --></td>
	    </tr>
		
		<tr>
		  <td class="TableRow1" width="156" align="center"><div align="right">下载地址一：</div></td>
								<td class="TableRow1" width="589">
								  <input name="dz1" type="text" class="txt"value="<%=editdz1%>" size="30" maxlength="200">
		  &nbsp;<!--webbot bot="Validation" s-display-name="下载地址一" b-value-required="TRUE" i-minimum-length="200" --></td>
	    </tr>
		<tr>
		  <td class="TableRow1" width="156" align="center"><div align="right">下载地址二：</div></td>
								<td class="TableRow1" width="589">
								  <input name="dz2" type="text" class="txt"value="<%=editdz2%>" size="30" maxlength="200">
		  &nbsp;<!--webbot bot="Validation" s-display-name="下载地址二" b-value-required="TRUE" i-minimum-length="200" --></td>
	    </tr>
<tr class=trb>
							  <td class="TableRow1">&nbsp;</td>
							  <td class="TableRow1"><input type=submit class=btn value="保存修改" name="B1">&nbsp;&nbsp;<input type="reset" class=btn value="重新填写" name="B2"></td>
	    </tr>
					  </table>
					  <table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.&nbsp;&nbsp;</font></td></tr>
</table>
					</div>
				</form>
				
	</div>

<%
rs.close
set rs=nothing
conn.close
set conn=nothing
%>