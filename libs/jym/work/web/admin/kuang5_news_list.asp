<% Response.Buffer = True %>
<%
'ON ERROR RESUME NEXT
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<html>

<head>
<!--#include file = language.asp -->

<LINK href="admin_style.css" type=text/css rel=StyleSheet>
<script language="JavaScript">
<!--
function FP_jumpMenu(el,frm,sel) {//v1.0
 var href=el.options[el.selectedIndex].value; if(sel) el.selectedIndex=0;
 if('_new'==frm) open(href); else eval(frm+".location='"+href+"'");
}
// -->
</script>
<base target="_self">
</head>

<body topmargin="0" leftmargin="0" rightmargin="0" bottommargin="0" marginwidth="0" marginheight="0">

<%
delid=trim(request("delid"))
tj=trim(request("tj"))
sh=trim(Request("sh"))
shsh=trim(Request("shsh"))
if sh="" then sh=1
delallid=trim(Request("delallid"))
id=trim(request("id"))
ontopid=trim(Request("ontopid"))
ontoplx=trim(Request("ontoplx"))


function hrefIDD(ID,filename)
	if filename<>"0" then
		hrefidd="../"&filename
	else
		hrefidd="../News_View.asp?NewsID="&ID
	end if
end function

if ontopid<>"" and ontoplx<>"" then

	if ontoplx="1" then
		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select ID,ontop,time,updat from [news] where ID="&ontopid&"  order by id asc",conn,1,3
		if rs.recordcount<>0 then
			ontoptime=rs("updat")
				set rs2 = Server.CreateObject("ADODB.RecordSet")
				rs2.Open "select id,ontop,time,updat from [NEWS] where updat>"&ontoptime&"  and ontop=3 order by updat asc , id asc",conn,1,3
				if rs2.recordcount<>0 then
				
					rs("updat")=rs2("updat")
					rs2("updat")=ontoptime
					rs2.update
					rs.update
				end if
				rs2.close:set rs2=nothing
		end if
		rs.close:set rs=nothing
	end if
	
	if ontoplx="0" then
		set rs = Server.CreateObject("ADODB.RecordSet")
		rs.Open "select ID,ontop,time,updat from [news] where ID="&ontopid&"   order by id asc",conn,1,3
		if rs.recordcount<>0 then
			ontoptime=rs("updat")
				set rs2 = Server.CreateObject("ADODB.RecordSet")
				rs2.Open "select id,ontop,time,updat from [NEWS] where updat<"&ontoptime&"  and ontop=3 order by updat desc , id desc",conn,1,3
				if rs2.recordcount<>0 then
				
					rs("updat")=rs2("updat")
					rs2("updat")=ontoptime
					rs2.update
					rs.update
				end if
				rs2.close:set rs2=nothing
		end if
		rs.close:set rs=nothing
	end if	
end if

if delid<>"" then
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select id,filename from [news] where ID="&delid&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		filename=rs("filename")
		if filename<>"0" then
			sdDel(rs("filename"))
		end if
	end if
	rs.close:set rs=nothing
  conn.Execute "delete from [news] where ID="&clng(delid)
  conn.Execute "delete from [newspl] where newsID="&clng(delid)
end if

if delallid<>"" then 
	delallid=replace(delallid," ","")
	delid=split(delallid,",")
	'Response.Write DELallID
	for i=0 to ubound(delid)
		if (isNumeric(delid(i))) then
		
				set rs = Server.CreateObject("ADODB.RecordSet")
				rs.Open "select id,filename from [news] where ID="&delid(i)&" order by id desc",conn,1,1
				if rs.recordcount<>0 then
					filename=rs("filename")
					if filename<>"0" then
						sdDel(rs("filename"))
					end if
				end if
				rs.close:set rs=nothing
						
			  conn.Execute "delete from [news] where ID="&clng(delid(i))
			  conn.Execute "delete from [newspl] where newsID="&clng(delid(i))
			  'Response.Write DELID(i)
		end if
	next
	
end if

if shsh<>"" and id<>"" then
	conn.Execute "update [news] set [sh]="&shsh&",[shUsername]='"&Request.Cookies("adminuser")&"' where id="&clng(id)
end if

if tj<>"" then
	conn.Execute = "update news set tj='"&tj&"' where ID="&id
end if
%>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr>
			<th colspan="4">
			文章/图片列表</th>
		</tr>
		
		<tr><td width="218" class=TableRow>
			分类显示：
<select size="1" onChange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="font-size: 9pt">
<option value>请选择栏目</option>
<option value=kuang5_news_list.asp?all=all>显示所有文章信息</option>
					  <%					  
					  sql = "select * from lm where lm<>'' order by id asc"
					  Set rs = Server.CreateObject("ADODB.RecordSet")
					  rs.Open sql,conn,1,1
					  while not rs.eof
					       'response.write "<optgroup label=(ID:"&rs("id")&")"&rs("lm")&">"
					       %>
					         <option value='kuang5_news_list.asp?lm=<%=rs("id")%>' <% if clng(lmid)=clng(rs("id")) then response.write " selected" %>>(ID:<%=rs("id")%>)<%=rs("lm")%></option>
					       <%
							sql2 = "select * from lm where lmid='"&rs("id")&"' order by id asc"
							Set rs2 = Server.CreateObject("ADODB.RecordSet")
							rs2.Open sql2,conn,1,1
							while not rs2.eof
							%>
							   <option value='kuang5_news_list.asp?lm=<%=rs2("id")%>' <% if clng(lmid)=clng(rs2("id")) then response.write " selected" %>>　├(ID:<%=rs2("id")%>)<%=rs2("lm2")%></option>
							<%
				        Set rs33 = Server.CreateObject("ADODB.RecordSet")
				        rs33.Open "select * from [lm] where lmid='"&rs2("id")&"' and LM3<>'' order by id desc",conn,1,1
				        while not rs33.eof
				        %>
				        	<option value='kuang5_news_list.asp?lm=<%=rs33("id")%>' <% if clng(lmid)=clng(rs33("id")) then response.write " selected" %>>　　├(ID:<%=rs33("id")%>)<%=rs33("lm3")%></option>
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
			</td>
<%if Request.Cookies("admindj")=1 then%>
			<!--webbot BOT="GeneratedScript" PREVIEW=" " startspan --><script Language="VBScript" Type="text/vbscript"><!--
function FrontPage_Form1_onsubmit()
  Set theForm = document.FrontPage_Form1

  If (theForm.title.value = "") Then
    MsgBox "请在 关键字 域中输入值。", 0, "有效性验证错误"
    theForm.title.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.title.value) < 1) Then
    MsgBox "在 关键字 域中，请至少输入 1 个字符。", 0, "有效性验证错误"
    theForm.title.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If

  If (Len(theForm.title.value) > 10) Then
    MsgBox "在 关键字 域中，请最多输入 10 个字符。", 0, "有效性验证错误"
    theForm.title.focus()
    FrontPage_Form1_onsubmit = False
    Exit Function
  End If
  FrontPage_Form1_onsubmit = True 
End Function
--></script><!--webbot BOT="GeneratedScript" endspan --><form method="POST" action="kuang5_news_list.asp" name="FrontPage_Form1">
						<td width="293" class=TableRow>
						<%
						set rs = Server.CreateObject("ADODB.RecordSet")
						rs.Open "select sh,id from [News] where sh=2 order by id desc",conn,1,1
							shs=rs.recordcount
						rs.close:set rs=nothing
						set rs = Server.CreateObject("ADODB.RecordSet")
						rs.Open "select sh,id from [News] where sh=0 order by id desc",conn,1,1
							hszs=rs.recordcount
						rs.close:set rs=nothing						
						%>
						<a href="?sh=0">查看回收站(<%=hszs%>)</a>　<a href="?sh=2">待审核文章(<%=shs%>)</a>　<a href="?sh=1">正常显示的文章</a></td>
						<td class=TableRow width="61">搜索文章</td>
						<td class=TableRow width="178">
						&nbsp;<!--webbot bot="Validation" s-display-name="关键字" b-value-required="TRUE" i-minimum-length="1" i-maximum-length="10" --><input type="text" name="title" size="15" maxlength="10" style="border-style: solid; border-width: 1px">&nbsp; <input type="submit" value="搜索" name="B1" style="border: 1px solid #000000; background-color: #FFFFFF"></td>
			</td>
		</tr>
<%end if%>


<%
lm=trim(request("lm"))
if lm<>"" then
  sql = "select * from lm where id="&lm
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
%>
		<tr>
			<td align=center><font color=ff0000><B>查看“<%=rs("lm")&rs("lm2")&rs("lm3")%>”的文章文章</b></font></td>
		</tr>
<%end if%>
	</table>
</form>
<%
if sh=0 then 
	Response.Write "<center><font style='font-size:15pt;line-height:160%;color=ff0000'><b>回收站的文章</b></font><BR><font color=ff0000>(回收站的文章就是不会显示在前台的文章!)</font>"
elseif sh=2 then
	Response.Write "<center><font style='font-size:15pt;line-height:160%;color=ff0000'><b>待审核文章</b></font>"	
end if
%>


<form action=?delall=1 method=post>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<%
			ccc=""
			if sh=1 then 
				ccc="../images/bj5.jpg"
			else
				ccc="../images/bg11.gif"
			end if
		%>
		<tr style="background-image: url('<%=ccc%>')">
			<th align="center" height="25">
			<font color="#FFFFFF">(编号)标题(阅读)</font></th>
			<th align="center" height="25">
			<font color="#FFFFFF">栏目</font></th>
			<th align="center" height="25">
			<font color="#FFFFFF">加入时间</font></th>
			<th align="center" height="25">
			<font color="#FFFFFF">加入人员</font></th>
			<th align="center" height="25">
			<font color="#FFFFFF">操作</font></th>
		</tr>
<%
lm=trim(request("lm"))
title=trim(request("title"))


  sql = "select title,adduser,id,lm,lm2,lm3,time,hit,ontop,updat,tj,titlecolor,pic,sh,filename,shusername from news where title<>'' "
  
	  if lm<>"" then 
	    sql = sql & " and (lm2='"&lm&"' or lm='"&lm&"' or lm3='"&lm&"') "
	  end if 
	  if title<>"" and lm="" then
	    sql = sql & " and title like '%"&title&"%' "
	  end if  
	  if Request.Cookies("admindj")="3" then
	    sql= sql &" and adduser='"&Request.Cookies("adminuser")&"' or sh=2  "
	  end if
	  if Request.Cookies("admindj")="2" then
	  	sql=sql & " and ( [sh]=2 or [sh]=3 or [adduser]='"&Request.Cookies("adminuser")&"') or [shusername]='"&Request.Cookies("adminuser")&"' "
	  end if
	  
	  if Request.Cookies("admindj")="1" then
	  	sql=sql & "  and sh="&sh&"  "
	  end if
	  
   sql= sql& "  order by ontop desc , updat desc  , id desc"
   
	'sql=" exec NewsListall"
  Set rs = Server.CreateObject("ADODB.RecordSet")
  rs.Open sql,conn,1,1
  if rs.recordcount<>0 then
	page=request("page")
	if page<>"" then page=int(page)
	rs.PageSize=20
	pagecount=rs.pagesize
	if page<=0 then page=1
	if request.QueryString("page")="" then page=1
	rs.AbsolutePage=page
	gg=rs.recordcount/pagecount
	gh=int(gg)
	if gh<=1 then gh=1
	if gg>gh then gh=gh+1
	gg=gh
	
	bbb=0
	
	for i=1 to pagecount
	
			   lm2=trim(rs("lm3"))
			    if lm2="0" or lm2="" then lm2=trim(rs("lm2"))
			    if lm2="0" or lm2="" then lm2=trim(rs("lm"))
			    if lm2="" then lm2=0
			    if (not isNumeric(lm2)) then
			    	lm2=0
			    end if
			   sql2 = "select * from lm where id="&lm2
			   Set rs2 = Server.CreateObject("ADODB.RecordSet")
			   rs2.Open sql2,conn,1,1
			   
			   if rs2.recordcount<>0 then
			   	fontcolor=rs2("fontcolor")
			   
			   	if rs("titlecolor")="默认颜色" then
			   	  fontcolor=rs2("fontcolor")
			   	else
			   	  fontcolor=rs("titlecolor")
			   	end if
			   end if





%>
		<tr <% if bbb=1 then Response.Write "style='background-color: #ffffff'"%>>
			<td class=tablerow1><%if rs("ontop")="5" then Response.Write "<b><font color=blue>[顶]</font></b>"%>(<%=rs("id")%>)<a href="<%=hrefIDD(rs("ID"),rs("filename"))%>" target=_blank title='<%=rs("title")%>'><font color=<%=trim(fontcolor)%>><%=titleb(rs("title"),18)%></font></a><font color=999999>(<%=rs("hit")%>)<%if trim(rs("pic"))<>"" then Response.Write "[图]"%></font>
			<%	
				if admindj<>"1" and rs("sh")="2" then
					Response.Write "<font color=FF0000>[未审]</font>"
				end if
				if rs("filename")<>"0" then
					Response.Write "<font color=blue>[静]</font>"
				end if
				if rs("sh")="0" then Response.Write "<font color=bbbbbb>[回收站中]</font>"
			%>
			</td>
			<td class=tablerow1 align=center>
			   <%

			   if rs2.recordcount<>0 then 
			      response.write rs2("lm")&rs2("lm2")&rs2("lm3")
			   else
			      response.write "<font color=blue>栏目不正确</font>" 
			   end if
			   %></td>
			<td class=tablerow1 align="center"><%=datetime(rs("time"))%></td>
			<td class=tablerow1 align=center>
			<p align="center"><%=rs("adduser")%></td>
			<td class=tablerow1 align=center>
			<%
			  if Request.Cookies("admindj")="1" then
			%>
			<p align="center">
			<%
			  if rs("tj")="不推荐" then
			    Response.Write "<a href=kuang5_news_list.asp?tj=推荐&id="&rs("ID")&"&page="&page&"&lm="&lm&" title='此文章没有推荐'>荐</a>&nbsp;"
			  else
			    Response.Write "<a href=kuang5_news_list.asp?tj=不推荐&id="&rs("ID")&"&page="&page&"&lm="&lm&" title='此文章已经推荐'><font color=red>荐</font></a>&nbsp;"
			  end if
			  %>
			   <%

			     ontop=rs("ontop")
			     if ontop=3 then
			       response.write "<a href=kuang5_news_ontop.asp?id="&rs("id")&"&ontop=5&page="&page&"&title="&title&"&lm="&lm&" title='此文章没固顶'>顶</a>&nbsp;"
			     else
			       response.write "<a href=kuang5_news_ontop.asp?id="&rs("id")&"&ontop=3&page="&page&"&title="&title&"&lm="&lm&" title='此文章已固顶'><font color=red>顶</font></a>&nbsp;"
			     end if
			   
			   end if
			   
			   if rs("adduser")=Request.Cookies("adminuser") or rs("shusername")=Request.Cookies("adminuser") or Request.Cookies("admindj")="1" then

			   %><a href="kuang5_news_add.asp?id=<%=rs("ID")%>" title='编辑此文章'>编辑</a> 
			  <a href=# onclick='window.open("NewsPL.asp?id=<%=rs("id")%>","newsview","width=680,height=400,top=70,left=150,scrollbars=yes" )' title='查看此文章的评论信息'>评</a>
			  <%end if
			  if Request.Cookies("admindj")="1" or Request.Cookies("admindj")="2" or rs("adduser")=Request.Cookies("adminuser") then
			  %>
			   <a onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' href=kuang5_news_list.asp?delid=<%=rs("id")%>&page=<%=page%>&lm=<%=lm%>&title=<%=title%> title='永久删除此文章'>删</a>
			   <input type="checkbox" name="DELallID" value="<%=rs("id")%>">
			   <%end if%>
			   <%
			   		if Request.Cookies("admindj")="1" or Request.Cookies("admindj")="2" then
			   			if rs("sh")="1" then 
			   				Response.Write "<a href=?id="&rs("id")&"&shsh=0&lm="&lm&"&sh="&sh&"&word="&word&" title='放入回收站中'><img width=16 height=16 border=0 src='images/isdel2.gif'></a>"
			   			elseif rs("sh")=2 then
			   				Response.Write "<a href=?id="&rs("id")&"&shsh=1&lm="&lm&"&sh="&sh&"&word="&word&">待审</a>"
			   			else
			   				Response.Write "<a href=?id="&rs("id")&"&shsh=1&lm="&lm&"&sh="&sh&"&word="&word&">还原</a>"
			   			end if
			   		end if
			   		if Request.Cookies("admindj")="1" then
			   			Response.Write "&nbsp;<a href='?ontopid="&rs("id")&"&ontoplx=1&lm="&lm&"&sh="&sh&"&word="&word&"&page="&page&"' title='顺序上升'>↑</a><a href='?ontopid="&rs("id")&"&ontoplx=0&lm="&lm&"&sh="&sh&"&word="&word&"&page="&page&"' title='顺序下降'>↓</a>"
			   		end if
			   %>
			   </td>
		</tr>
<%
bbb=bbb+1
if bbb>=2 then bbb=0
response.flush
rs.movenext
if rs.eof then exit for
next
else
  Response.Write "<tr><td colspan=4>暂无信息</td></tr>"
   end if
%>
<tr><td class=tablerow1 colspan="4"><table border="0" cellpadding="0" cellspacing="1" align="right" class="Tableborder5">
    <tr>
      
    <td class="tabletitle1">
<%
if rs.recordcount<>0 then
  if page>1 then%>
     <a href='<%=request.servervariables("URL")%>?page=1&title=<%=title%>&lm=<%=lm%>&sh=<%=sh%>'>首页</a>
     <a href='<%=request.servervariables("URL")%>?page=<%=page-1%>&title=<%=title%>&lm=<%=lm%>&sh=<%=sh%>'>上一页</a>
  <%end if%>
  <%if page<gg then%>
     <a href='<%=request.servervariables("URL")%>?page=<%=page+1%>&title=<%=title%>&lm=<%=lm%>&sh=<%=sh%>'>下一页</a>
     <a href='<%=request.servervariables("URL")%>?page=<%=rs.pagecount%>&title=<%=title%>&lm=<%=lm%>&sh=<%=sh%>'>尾页</a>
  <%end if%>
　共<%=rs.recordcount%>条　每页显示<%=pagecount%>条　　第<%=page%>页　共<%=rs.pagecount%>页				
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
          <option value="<%=request.servervariables("URL")%>?page=<%=i%>&title=<%=title%>&lm=<%=lm%>&sh=<%=sh%>" <%if page=i then response.write "selected"%>>第<%=i%>页</option>
        <%next%>
  </select>


</td>
</tr></table></td><td class=tablerow1 align="center"><input onclick='{if(confirm("您确定删除吗?此操作将不能恢复!")){return true;}return false;}' type="submit" name="" value=批量删除>
<%
end if
Response.flush  
%></td></tr>
	</table>
	<center><table border=0>
<tr><td align=center height=30 class=tims style="font-family:Verdana, Arial; font-size:9px;"> <font style="font-family:Verdana,Arial; font-size:9px;">Copyright &copy; <a href="http://www.kuang5.com/" target=_blank color=#CC3300>Kuang5&nbsp;CMS&nbsp;2.2</a> All Rights Reserved.</font>&nbsp;&nbsp;</td></tr>
</table></center>
</form>
</body>
</html>