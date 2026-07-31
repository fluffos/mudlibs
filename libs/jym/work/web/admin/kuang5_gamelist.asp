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
name=Request("name")
ip=Request("ip")
addtime=Request("addtime")
ap=Request("ap")
dlq=Request("dlq")
color=Request("color")


if editid<>"" and trim(Request("name"))="" and trim(Request("ip"))="" and trim(Request("addtime"))="" and trim(Request("ap"))="" and trim(Request("color"))="" and trim(Request("dlq"))="" then
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open "select * from [gamelist] where id="&clng(editid),conn,1,1
  if rs.recordcount<>0 then
     editname=rs("name")
     editip=rs("ip")
     editaddtime=rs("addtime")
     editap=rs("ap")
	 editcolor=rs("color")
	 editdlq=rs("dlq")
  end if
  rs.close
  set rs=nothing
elseif saveid="" and trim(Request("name"))<>"" and trim(Request("ip"))<>"" and trim(Request("addtime"))<>"" and trim(Request("ap"))<>"" and trim(Request("color"))<>"" and trim(Request("dlq"))<>"" then
     conn.Execute "insert into [gamelist] ([name],[ip],[addtime],[ap],[color],[dlq]) values('"&name&"','"&ip&"','"&addtime&"','"&ap&"','"&color&"','"&dlq&"')"   
     Response.Redirect "kuang5_gamelist.asp"
elseif saveid<>"" and trim(Request("name"))<>"" and trim(Request("ip"))<>"" and trim(Request("addtime"))<>"" and trim(Request("ap"))<>"" and trim(Request("color"))<>"" and trim(Request("dlq"))<>"" then
   conn.Execute "update [gamelist] set name='"&name&"',ip='"&ip&"',addtime='"&addtime&"',ap='"&ap&"',color='"&color&"',dlq='"&dlq&"' where id="&clng(saveid)
   Response.Redirect "kuang5_gamelist.asp"
elseif delid<>"" then
   conn.Execute "delete from [gamelist] where ID="&CInt(delid)
end if
%>
	<div align="center">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr class="tr">
			<th width="281">服务器名</th>
			<th width="203">服务器ＩＰ</th>
			<th width="203">开放时间</th>
			<th width="176">服务器状态</th>
			<th width="92">
			  <strong><font color="#FFFFFF">操　作</font></strong></td>
		</th>
		<%
		Set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select * from [gamelist] order by id desc",conn,1,1
		
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
			<td class=tablerow1 width="281"><font color="#666666">(编号:<%=rs("id")%>)</font><font color="<%=rs("color")%>"><%=rs("name")%></font><br></td>
			<td class=tablerow1 width="203"><font color="<%=rs("color")%>"><%=rs("ip")%></font></td>
			<td class=tablerow1 width="203"><font color="<%=rs("color")%>"><%=rs("addtime")%></font></td>
			<td class=tablerow1 width="176"><font color="<%=rs("color")%>"><%=rs("ap")%></font></td>
			<td class=tablerow1 width="92" align="center">
			<p align="center"><a href="kuang5_gamelist.asp?editid=<%=rs("ID")%>">修改</a>　<a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href="kuang5_gamelist.asp?delid=<%=rs("id")%>">删除</a></td>
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
<td class=tablerow1 colspan=5>
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

  if (theForm.name.value == "")
  {
    alert("请在 服务器名标题 域中输入值。");
    theForm.name.focus();
    return (false);
  }

  if (theForm.name.value.length < 1)
  {
    alert("在 服务器名标题 域中，请至少输入 1 个字符。");
    theForm.name.focus();
    return (false);
  }

  if (theForm.name.value.length > 50)
  {
    alert("在 服务器名标题 域中，请最多输入 50 个字符。");
    theForm.name.focus();
    return (false);
  }

  if (theForm.ip.value == "")
  {
    alert("请在 服务器IP 域中输入值。");
    theForm.ip.focus();
    return (false);
  }

  if (theForm.ip.value.length < 1)
  {
    alert("在 服务器IP 域中，请至少输入 1 个字符。");
    theForm.ip.focus();
    return (false);
  }

  if (theForm.ip.value.length > 100)
  {
    alert("在 服务器IP 域中，请最多输入 100 个字符。");
    theForm.ip.focus();
    return (false);
  }
  
    if (theForm.addtime.value == "")
  {
    alert("请在 开区时间 域中输入值。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length < 1)
  {
    alert("在 开区时间 域中，请至少输入 1 个字符。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length > 50)
  {
    alert("在 开区时间 域中，请最多输入 50 个字符。");
    theForm.addtime.focus();
    return (false);
  }

    if (theForm.addtime.value == "")
  {
    alert("请在 服务器状态 域中输入值。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length < 1)
  {
    alert("在 服务器状态 域中，请至少输入 1 个字符。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length > 100)
  {
    alert("在 服务器状态 域中，请最多输入 100 个字符。");
    theForm.addtime.focus();
    return (false);
  }

    if (theForm.addtime.value == "")
  {
    alert("请在 登陆器地址 域中输入值。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length < 1)
  {
    alert("在 登陆器地址 域中，请至少输入 1 个字符。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length > 150)
  {
    alert("在 登陆器地址 域中，请最多输入 150 个字符。");
    theForm.addtime.focus();
    return (false);
  }
    if (theForm.addtime.value == "")
  {
    alert("请在 颜色 域中输入值。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length < 1)
  {
    alert("在 颜色 域中，请至少输入 1 个字符。");
    theForm.addtime.focus();
    return (false);
  }

  if (theForm.addtime.value.length > 50)
  {
    alert("在 颜色 域中，请最多输入 50 个字符。");
    theForm.addtime.focus();
    return (false);
  }


  return (true);
}
//--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_gamelist.asp?saveid=<%=editid%>" onSubmit="return FrontPage_Form1_Validator(this)" language="JavaScript" name="FrontPage_Form1">
					<div align="center">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
							<tr class="tr">
							  <th colspan="2" align="left">&nbsp;添加/修改服务器列表</th>
						  </tr>
							<tr class="tr">
							  <td class="TableRow1" width="216" align="center""><div align="right">服务器名：</div></td>
								<td class="TableRow1" width="544"><div align="left">
							    <!--webbot bot="Validation" s-display-name="服务器名标题" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="200" -->
							    <input type="text" class="txt"name="name" size="30" value="<%=editname%>" maxlength="20">
						      </div></td>
							</tr>
							<tr class="tr">
							  <td class="TableRow1" width="216" align="center"><div align="right">服务器ＩＰ：</div></td>
								<td class="TableRow1" width="544">
								  <input name="ip" type="text" class="txt"value="<%=editip%>" size="30" maxlength="100">
							  &nbsp;<!--webbot bot="Validation" s-display-name="服务器名内容ＩＰ" b-value-required="TRUE" i-minimum-length="200" --></td>
							</tr>
<tr class="tr">
		  <td class="TableRow1" width="216" align="center"><div align="right">开放时间：</div></td>
								<td class="TableRow1" width="544">
								  <input name="addtime" type="text" class="txt" value="<%=editaddtime%>" size="30" maxlength="50">
		  &nbsp;<!--webbot bot="Validation" s-display-name="开区时间" b-value-required="TRUE" i-minimum-length="200" --></td>
	    </tr>
<tr class="tr">
		  <td class="TableRow1" width="216" align="center"><div align="right">服务器状态：</div></td>
								<td class="TableRow1" width="544">
								  <input name="ap" type="text" class="txt"value="<%=editap%>" size="30" maxlength="100">
							  &nbsp;<!--webbot bot="Validation" s-display-name="服务器状态" b-value-required="TRUE" i-minimum-length="200" --></td>
	    </tr>
		
<tr class="tr">
		  <td class="TableRow1" width="216" align="center"><div align="right">登陆器下载地址：</div></td>
								<td class="TableRow1" width="544">
<input name="dlq" type="text" class="dlq" value="<%=editdlq%>" size="30" maxlength="50">
		  &nbsp;</td>
	    </tr>		
		
<tr class="tr">
		  <td class="TableRow1" width="216" align="center"><div align="right">颜色：</div></td>
								<td class="TableRow1" width="544">
<select size="1" name="color">
	            <option value="#000000">默认黑色</option>
					<%
					ii=255
					for i=16 to 255
						Randomize
						an=""
						an= int((255-16+1) * RND +16)
						a=hex(i)
						b=hex(ii)
						c=hex(i)
						'i=i+99
						ccc=a+b+c
						'Response.Write i&":<font color="&ccc&">"&CCC&"</font><br>"
						%>
						<OPTION <% if titlecolor="#"&ccc&"" then response.write " selected "%>  value="#<%=ccc%>" style="background-color:#<%=ccc%>"></OPTION>
						
						<%
						ii=ii-1
					next
					ii=255
					for i=16 to 255
						Randomize
						an=""
						an= int((255-16+1) * RND +16)
						a=hex(i)
						b=hex(ii)
						c=hex(ii)
						'i=i+99
						ccc=a+b+c
						'Response.Write i&":<font color="&ccc&">"&CCC&"</font><br>"
						%>
						<OPTION <% if titlecolor="#"&ccc&"" then response.write " selected "%>  value="#<%=ccc%>" style="background-color:#<%=ccc%>"></OPTION>
						
						<%
						ii=ii-1
					next
					ii=255
					for i=16 to 255
						Randomize
						an=""
						an= int((255-16+1) * RND +16)
						a=hex(i)
						b=hex(i)
						c=hex(i)
						'i=i+99
						ccc=a+b+c
						'Response.Write i&":<font color="&ccc&">"&CCC&"</font><br>"
						%>
						<OPTION <% if titlecolor="#"&ccc&"" then response.write " selected "%>  value="#<%=ccc%>" style="background-color:#<%=ccc%>"></OPTION>
						
						<%
						ii=ii-1
					next
					%>	            
	            <OPTION <%if titlecolor="#000000" then response.write "selected"%> value="#000000" style="background-color:#000000"></OPTION>
                <OPTION <%if titlecolor="#FFFFFF" then response.write "selected"%> value="#FFFFFF" style="background-color:#FFFFFF"></OPTION>
                <OPTION <%if titlecolor="#008000" then response.write "selected"%> value="#008000" style="background-color:#008000"></OPTION>
                <OPTION <%if titlecolor="#800000" then response.write "selected"%> value="#800000" style="background-color:#800000"></OPTION>
                <OPTION <%if titlecolor="#808000" then response.write "selected"%> value="#808000" style="background-color:#808000"></OPTION>
                <OPTION <%if titlecolor="#000080" then response.write "selected"%> value="#000080" style="background-color:#000080"></OPTION>
                <OPTION <%if titlecolor="#800080" then response.write "selected"%> value="#800080" style="background-color:#800080"></OPTION>
                <OPTION <%if titlecolor="#808080" then response.write "selected"%> value="#808080" style="background-color:#808080"></OPTION>
                <OPTION <%if titlecolor="#FFFF00" then response.write "selected"%> value="#FFFF00" style="background-color:#FFFF00"></OPTION>
                <OPTION <%if titlecolor="#00FF00" then response.write "selected"%> value="#00FF00" style="background-color:#00FF00"></OPTION>
                <OPTION <%if titlecolor="#00FFFF" then response.write "selected"%> value="#00FFFF" style="background-color:#00FFFF"></OPTION>
                <OPTION <%if titlecolor="#FF00FF" then response.write "selected"%> value="#FF00FF" style="background-color:#FF00FF"></OPTION>
                <OPTION <%if titlecolor="#FF0000" then response.write "selected"%> value="#FF0000" style="background-color:#FF0000"></OPTION>
                <OPTION <%if titlecolor="#0000FF" then response.write "selected"%> value="#0000FF" style="background-color:#0000FF"></OPTION>
                <OPTION <%if titlecolor="#008080" then response.write "selected"%> value="#008080" style="background-color:#008080"></OPTION>
					</select></td>
	    </tr>	
		
		
		
		
		
		
		
		
		
		
<tr class=trb>
							  <td class="TableRow1">&nbsp;</td>
							  <td class="TableRow1"><input type=submit class=btn value="保存修改" name="B1">&nbsp;&nbsp;<input type="reset" class=btn value="重新填写" name="B2"></td>
			  </tr>
					  </table>
					  <table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
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