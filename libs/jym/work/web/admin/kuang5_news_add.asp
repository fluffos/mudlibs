<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<html>
<head>
<!--#include file = language.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
</head>

<body topmargin="0" leftmargin="0" rightmargin="0" bottommargin="0" marginwidth="0" marginheight="0">
<%
'ON ERROR RESUME NEXT
titlecolor=trim(request("titlecolor"))
tgid=trim(request("tgid"))
ztid=0
eaddtime=year(now())&"-"&month(now())&"-"&day(now())&" "&hour(time())&":"&Minute(now())&":"&Second(now())
ehit=0
zz=session("kuang5__user")
ehtml=Request.Cookies("html")

if request("id")<>"" then
  id=request("id")
  sql = "select * from news where id="&id
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
  title=rs("title")
  htitle=rs("htitle")
  tj=trim(rs("tj"))
  ztid=rs("ztid")
  lmid=rs("lm3")
    if lmid="0" then lmid=rs("lm2")
      if lmid="0" then lmid=rs("lm")
  lm2id=rs("lm2")
  ehtml=rs("html")
  pic=trim(rs("pic"))
  content=rs("content")
  url=rs("url")
  titlecolor=rs("titlecolor")
  xgnews=rs("xgnews")
  ontop=rs("ontop")
  zz=rs("zz")
  laiyuan=rs("laiyuan")
  piczz=rs("piczz")
  eaddtime=datetime(rs("time"))
  eHit=rs("hit")
  
  rs.close
  set rs=nothing
else
  lmid=trim(request("lmid"))
  html=trim(request("html"))
end if

if tgid<>"" then
   Set rs = Server.CreateObject("ADODB.RecordSet")
   rs.Open "select * from [usertougao] where id="&tgid,conn,1,1
   title=rs("title")
   content=rs("content")
   zz=rs("adduser")
   lmid=rs("lmid")
   eaddtime=datetime(rs("addtime"))
end if
if lmid="" then lmid=00
if (not isNumeric(ztid)) then
	ztid=0
end if

if (not isNumeric(eHit)) then
	ehit=0
end if
%>


		<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.title.value = "") Then
    MsgBox "请在 文章信息标题 域中输入值。", 0, "有效性验证错误"
    theForm.title.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.title.value) < 1) Then
    MsgBox "在 文章信息标题 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.title.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.title.value) > 100) Then
    MsgBox "在 文章信息标题 域中，请最多输入 100 个字符。", 0, "有效性验证错误"
    theForm.title.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.lm.selectedIndex < 0) Then
    MsgBox "请选择“栏目分类”选项中的一项。", 0, "有效性验证错误"
    theForm.lm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.lm.selectedIndex = 0) Then
    MsgBox "第一个“栏目分类”选项无效。 请选择其他选项中的一项。", 0, "有效性验证错误"
    theForm.lm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.lm.selectedIndex < 0) Then
    MsgBox "请选择“栏目分类”选项中的一项。", 0, "有效性验证错误"
    theForm.lm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.lm.selectedIndex = 0) Then
    MsgBox "第一个“栏目分类”选项无效。 请选择其他选项中的一项。", 0, "有效性验证错误"
    theForm.lm.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.addtime.value = "") Then
    MsgBox "请在 日期时间 域中输入值。", 0, "有效性验证错误"
    theForm.addtime.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.addtime.value) < 1) Then
    MsgBox "在 日期时间 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.addtime.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.addtime.value) > 30) Then
    MsgBox "在 日期时间 域中，请最多输入 30 个字符。", 0, "有效性验证错误"
    theForm.addtime.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (theForm.hit.value = "") Then
    MsgBox "请在 阅读数 域中输入值。", 0, "有效性验证错误"
    theForm.hit.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.hit.value) < 1) Then
    MsgBox "在 阅读数 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.hit.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.hit.value) > 9) Then
    MsgBox "在 阅读数 域中，请最多输入 9 个字符。", 0, "有效性验证错误"
    theForm.hit.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="../kuang5_news_add_save.asp?id=<%=id%>&tgid=<%=tgid%>" name="FrontPage_Form1">
			<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
						<tr>
			<th colspan="3">
			添加/修改文章</th>
		</tr>
				<tr>
					<td class="TableRow" width="11%" align="center">文章信息标题</td>
					<td class="TableRow" width="41%">
					&nbsp;<!--webbot bot="Validation" s-display-name="文章信息标题" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="100" --><input type="text" name="title" size="48" maxlength="100" value='<%=title%>'></td>
					<td class="TableRow" width="45%">
					<select size="1" name="titlecolor">
	            <option value=" ">默认颜色</option>
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
                <OPTION <%if titlecolor="#000000" then response.write "selected"%> value="#000000" style="background-color:#000000"></OPTION>
                <OPTION <%if titlecolor="#800000" then response.write "selected"%> value="#800000" style="background-color:#800000"></OPTION>
                <OPTION <%if titlecolor="#800000" then response.write "selected"%> value="#800000" style="background-color:#800000"></OPTION>
                <OPTION <%if titlecolor="#000080" then response.write "selected"%> value="#000080" style="background-color:#000080"></OPTION>
                <OPTION <%if titlecolor="#800080" then response.write "selected"%> value="#800080" style="background-color:#800080"></OPTION>
                <OPTION <%if titlecolor="#808080" then response.write "selected"%> value="#808080" style="background-color:#808080"></OPTION>
                <OPTION <%if titlecolor="#FFFF00" then response.write "selected"%> value="#FFFF00" style="background-color:#FFFF00"></OPTION>
                <OPTION <%if titlecolor="#ff0000" then response.write "selected"%> value="#ff0000" style="background-color:#ff0000"></OPTION>
                <OPTION <%if titlecolor="#00FFFF" then response.write "selected"%> value="#00FFFF" style="background-color:#00FFFF"></OPTION>
                <OPTION <%if titlecolor="#FF00FF" then response.write "selected"%> value="#FF00FF" style="background-color:#FF00FF"></OPTION>
                <OPTION <%if titlecolor="#FF0000" then response.write "selected"%> value="#FF0000" style="background-color:#FF0000"></OPTION>
                <OPTION <%if titlecolor="#0000FF" then response.write "selected"%> value="#0000FF" style="background-color:#0000FF"></OPTION>
                <OPTION <%if titlecolor="#008080" then response.write "selected"%> value="#008080" style="background-color:#008080"></OPTION>
					</select>
					</td>
				</tr>
				<tr>
					<td class="TableRow" width="11%" align="center">副标题</td>
					<td class="TableRow" width="41%">&nbsp;<input type="text" name="htitle" size="48" maxlength="100" value='<%=htitle%>'></td>
					<td class="TableRow" width="45%"><input type="submit" value="　保　存　"><textarea name="content" style="display:none" cols="1" rows="1"><%if content<>"" then response.write content%></textarea></td>
				</tr>
				<tr>
					<td class="TableRow" width="11%" align="center">栏目选择</td>
					<td class="TableRow" width="41%" colspan="2">&nbsp;<%
if Request.Cookies("admindj")="1" then
%>
<!--webbot bot="Validation" s-display-name="栏目分类" b-value-required="TRUE" b-disallow-first-item="TRUE" --><select size="1" name="lm">
					<option>请选择</option>
					  <%					  
					  sql = "select * from lm where lm<>'' order by id asc"
					  Set rs = Server.CreateObject("ADODB.RecordSet")
					  rs.Open sql,conn,1,1
					  while not rs.eof
					  %>
					       <option value='<%=rs("id")%>|0|0' <% if clng(lmid)=clng(rs("id")) then response.write " selected" %>><%=rs("lm")%>(1级)</option>
					  <%	sql2 = "select * from lm where lmid='"&rs("id")&"' order by id asc"
							Set rs2 = Server.CreateObject("ADODB.RecordSet")
							rs2.Open sql2,conn,1,1
							while not rs2.eof
							%>
							   <option value='<%=rs("id")%>|<%=rs2("id")%>|0' <% if clng(lmid)=clng(rs2("id")) then response.write " selected" %>>　├<%=rs2("lm2")%>(2级)</option>
							<%
							   	Set rs33 = Server.CreateObject("ADODB.RecordSet")
							   	rs33.Open "select * from [lm] where lm3<>'' and lmid='"&rs2("id")&"' order by id asc",conn,1,1
							   	while not rs33.eof
							%>
								<option value='<%=rs2("lmid")%>|<%=rs2("id")%>|<%=rs33("id")%>' <% if clng(lmid)=clng(rs33("id")) then response.write " selected" %>>　　├<%=rs33("lm3")%>(3级)</option>
							<%
							   	rs33.movenext
							   	wend
							rs2.movenext
							wend
					  rs.movenext
					  wend 
					  rs.close
					  set rs=nothing
					 
					%>
					
					</select>
<%else%>&nbsp;<!--webbot bot="Validation" s-display-name="栏目分类" b-value-required="TRUE" b-disallow-first-item="TRUE" --><select size="1" name="lm">
				<option>请选择</option>
					  <%
					  kuang5_sql = "select * from admin where [user]='"&adminuser&"' order by id desc"
					  Set kuang5_rs = Server.CreateObject("ADODB.RecordSet")
					  kuang5_rs.Open kuang5_sql,conn,1,1
					  kuang5_lmid=kuang5_rs("lmid")
					  for kkk=1 to 31
						  kuang5_lmid=replace(kuang5_lmid,chr(i),"")
					  next
					 'Response.Write kuang5_lmid
					  
					   array_kuang5_lmid=split(kuang5_lmid,",") 
					   For i=0 to ubound(array_kuang5_lmid)
					        aaa=array_kuang5_lmid(i)  '取出编辑者拥有的权限ID号.
							if aaa="" then aaa=0
							lm_1_sql = "select * from lm where id="&aaa
							Set lm_1_rs = Server.CreateObject("ADODB.RecordSet")
							lm_1_rs.Open lm_1_sql,conn,1,1

							while not lm_1_rs.eof
							  if lm_1_rs("lm")<>"" then
							%>
							   <option value='<%=lm_1_rs("id")%>|0|0' <% if clng(lmid)=clng(lm_1_rs("id")) then response.write " selected" %>><%=lm_1_rs("lm")%>(1级)
							   </option>
							<%
							  ElseIf lm_1_rs("lm2")<>"" then
							%>
							   <option value='<%=lm_1_rs("lmid")%>|<%=lm_1_rs("id")%>|0' <% if clng(lmid)=clng(lm_1_rs("id"))  then response.write " selected" %>>　├ <%=lm_1_rs("lm2")%>(2级)</option>
							<%

				               Elseif lm_1_rs("lm3")<>"" then
							       get_1_id_sql="select lmid from [lm] where id="&clng(lm_1_rs("lmid"))
								   set  get_1_id_rs = Server.CreateObject("ADODB.RecordSet")
							       get_1_id_rs.Open get_1_id_sql,conn,1,1
								   lmid31=get_1_id_rs("lmid")
								   get_1_id_rs.close
								   set get_1_id_rs=nothing
							%>
								<option value='<%=lmid31%>|<%=lm_1_rs("lmid")%>|<%=lm_1_rs("id")%>' <% if clng(lmid)=clng(lm_1_rs("id")) then response.write " selected" %>>　　├ <%=lm_1_rs("lm3")%>(3级)</option>
							<%
                              end if '结尾配对lm_1_rs("lm")<>""


							     lm_1_rs.movenext
							wend
							lm_1_rs.close
							set lm_1_rs=nothing
						next
				        kuang5_rs.close
						set kuang5_rs=nothing

					%>
					
					</select>

<%end if%></td>
				</tr>
				<tr>
					<td class="TableRow" colspan="3">
					<iframe ID="eWebEditor1" src="../edit/ewebeditor.htm?id=content&style=coolblue" frameborder="0" scrolling="no" width="100%" HEIGHT="399"></iframe></td>
				</tr>
				<tr>
					<td class="TableRow" width="53%" colspan="2">
					
					&nbsp;<input type="checkbox" <% if pic<>"" then Response.Write " checked "%> name="tuwen" value="1" id=tu><label for=tu>图片文章</label>
					<%
						if Request.Cookies("admindj")="1" then
					%>
					　<input type="checkbox" <%if tj="推荐" then response.write " checked "%> name="tj"  value="推荐" id=tj><label for=tj>推荐文章</label>　<input type="checkbox" name="ontop" <%if ontop=5 then response.write " checked "%> value="5" id=ontop><label for=ontop>固顶</label>
					<%
						end if
						if config("lrySH")=1 or Request.Cookies("admindj")="1" then
					%>
					　<input type="checkbox" <%if ehtml="1" then response.write " checked "%> name="html" value="1" id=html><label for=html>生成HTML</label>
					<%
						end if
					%>
					</td>
					<td class="TableRow" width="45%">分页标志：$$分页$$&nbsp; （可复制插入多个）</td>
				</tr>
					<%
						if Request.Cookies("admindj")="1" then
					%>				
				<tr>
					<td class="TableRow" width="11%" align="center">添加时间</td>
					<td class="TableRow" width="41%">
					&nbsp;<!--webbot bot="Validation" s-display-name="日期时间" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="30" --><input type="text" name="addtime" size="20" value="<%=eaddtime%>" maxlength="30"> 格式:<%=year(now())&"-"&month(now())&"-"&day(now())&" "&hour(time())&":"&Minute(now())&":"&Second(now())%></td>
					<td class="TableRow" width="45%">　</td>
				</tr>
				<tr>
					<td class="TableRow" width="11%" align="center">阅读数</td>
					<td class="TableRow" width="41%">&nbsp;<!--webbot bot="Validation" s-display-name="阅读数" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="9" --><input type="text" name="hit" size="20" value="<%=ehit%>" maxlength="9"> </td>
					<td class="TableRow" width="45%">　</td>
				</tr>
					<%
						end if
					%>				
				<tr>
					<td class="TableRow" width="97%" colspan="3">
					<div align="center">
						<table border="0" cellpadding="0" cellspacing="0" width="743" id="table5">
							<tr>
								<td class="TableRow" width="78">
								<p align="center">文章来源</td>
								<td class="TableRow" width="169">&nbsp;
								<input type="text" name="laiyuan" size="14" maxlength="40" value="<%=laiyuan%>"></td>
								<td class="TableRow" width="124">
								<p align="center">文章作者</td>
								<td class="TableRow" width="124">
								<input type="text" name="zz" size="20" value="<%=zz%>" maxlength="50"></td>
								<td class="TableRow" width="124">
								<p align="center">图片作者</td>
								<td class="TableRow" width="124">
								<input type="text" name="piczz" size="20" value="<%=piczz%>" maxlength="50"></td>
							</tr>
						</table>
					</div>
					</td>
				</tr>
				<tr>
					<td class="TableRow" width="11%" align="center">跳转URL</td>
					<td class="TableRow" width="41%">&nbsp;<input type="text" name="URL" size="47" value='<%=url%>'></td>
					<td class="TableRow" width="45%">填写网址,自动打开此URL。不显示文章内容</td>
				</tr>
				<tr>
					<td class="TableRow" width="11%">
					<p align="center">缩略图地址</td>
					<td class="TableRow" width="41%">
					&nbsp;<input type="text" name="pic" size="47" value="<%=pic%>"></td>
					<td class="TableRow" width="45%">此地址将做为图片文章的缩略图，如果为空，默认是文章内容中第一幅图片。</td>
				</tr>
				<tr>
					  <td class=TableRow align="center">缩略图上传</td>
			  <td class=TableRow>&nbsp;<iframe name="ad" frameborder=0 width=100% height=23 scrolling=no src="../edit/sitedde43vc125jve4g45f.asp"></iframe></td>
              <td class=TableRow>&nbsp;</td>
	</tr>
				<tr>
					<td class="TableRow" width="11%">
					<p align="center">相关文章</td>
					<td class="TableRow" width="41%">
					&nbsp;<input type="text" name="xgnews" size="20" value="<%=xgnews%>"> 
					(填写关键字)</td>
					<td class="TableRow" width="45%">　</td>
				</tr>
				<tr><td class="TableRow1" colspan="3" align="center">			<input type="submit" value="　保存修改　">  &nbsp  <input type="reset" value="　重新填写　" name="B2"></td></tr>
				</table>
				<center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
</table></center>
		</form>



</body>

</html>
<%
conn.close
set conn=nothing

%>