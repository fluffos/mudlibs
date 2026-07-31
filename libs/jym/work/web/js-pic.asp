<!--#include file="kuang5_h.asp"-->
<!--#include file="head.asp"-->
<!--#include file = titleb.asp -->
<%
'ON ERROR RESUME NEXT
path=finddir(request.servervariables("URL"))
lm=trim(request("lm"))
if lm="" then lm=trim(Request("lm2"))
page=trim(request("page"))
if page="" then page=1
if lm="" then lm=0

if lm2="" then lm2=lm
if lm="" then lm=lm2
if lm2="" then lm2=0

if (not isNumeric(lm)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数，请勿随意提交数据！');</Script>"
  response.end  
end if

function pictulist()
			if openwindow="1" then 
				open="_blank"
			else
				open="_top"
			end if
%>
			<table id=_ctl0_TopImage_Index_Class_15_TopImgList cellspacing=0 Align=Center border=0 style=width:100%;border-collapse:collapse;>
			<%
			sql="select id,title,pic,sh,lm,lm2,lm3,hit,ontop,filename,ontop from [news] where ( [pic] like '%.jpg' or [pic] like '%.gif'  ) and sh=1 "
			if lm<>"0" then sql=sql&" and (lm='"&lm&"' or lm2='"&lm&"' or lm3='"&lm&"') "
			sql=sql&" order by ontop desc , updat desc , id desc"
			set rs = Server.CreateObject("ADODB.RecordSet")
			rs.Open sql,conn,1,1
			if rs.recordcount <>0 then
			
			page=int(request("page"))
			rs.PageSize=xy
			pagecount=rs.pagesize
			if page<=0 then page=1
			if request("page")="" then page=1
			rs.AbsolutePage=page
			
			for i=1 to picy
			
			%>
			<tr>
				<%
					for xxxx=1 to picx
						if pictitle<>0 then
						  ttt="<font color="&pictitlecolor&" style='font-size:"&pictitlesize&"pt'>"&titleb(rs("title"),pictitle)&"</font>"
						end if
						title=rs("title")
						id=rs("id")
				%>
			<td align=Center>
<table width=165 border=0 cellpadding=0 cellspacing=0>
  <tr> 
    <td colspan=2 valign=top rowspan=2> 
      <table width=100% border=0 cellpadding=0 cellspacing=1 bgcolor=333333>
        <tr> 
          <td width=165 height=135 bgcolor=cdcdcd valign=middle align=center><a href=<%=path%><%=hrefID(ID,rs("filename"))%> target='<%=open%>' title='<%=title%>'><Script Language=JavaScript>ShowPreviewImg('<%=rs("pic")%>',150,110,'True','标题:快乐230区&#13;&#10;点击:320');</Script></a>
		<div id=_ctl0_TopImage_Index_Class_15_TopImgList__ctl0_TitlePanel>
			
			<div align=center><%=ttt%></div>
		
		</div></td>
        </tr>
      </table>
    </td>
    <td width=4 height=4 valign=top></td>
  </tr>
  <tr> 
    <td height=131 bgcolor=333333></td>
  </tr>
  <tr> 
    <td width=4 height=4 valign=top></td>
    <td width=161 bgcolor=333333></td>
    <td bgcolor=333333></td>
  </tr>
</table></td>
				<%
					rs.movenext
					if rs.eof then exit for
					next
				%>
			</tr>
			<%
			if rs.eof then exit for
			next
			
			end if
			%>
			</table>
			<BR>
			<center>
			<%if rs.recordcount<>0 then
			if page>1 then
			response.write "<a href="&request.servervariables("URL")&"?page=1&lm="&lm&">首页</a>　"
			response.write "<a href="&request.servervariables("URL")&"?page="&page-1&"&lm="&lm&">上一页</a>　"
			end if
			if page<rs.pagecount then
			response.write "<a href="&request.servervariables("URL")&"?page="&page+1&"&lm="&lm&">下一页</a>　"
			response.write "<a href="&request.servervariables("URL")&"?page="&rs.pagecount&"&lm="&lm&">尾页</a>　"
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
			<select size="1" onchange="FP_jumpMenu(this,'window',false)" id="id1" name="D1" style="font-size: 9pt; border-style: solid; border-width: 1px">
			<%for i=1 to rs.pagecount%>
			<option value="<%=request.servervariables("URL")%>?page=<%=i%>&lm=<%=lm%>" <%if page=i then response.write "selected"%> style="font-size: 9pt">第<%=i%>页</option>
			<%next%>
			</select>
			<%end if%>
			</center>

<%
end function

	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [lm] where id="&lm&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		mbid=rs("mb")
		lmname=rs("lm")&rs("lm2")&rs("lm3")
	else
		set rs2 = Server.CreateObject("ADODB.RecordSet")
		rs2.Open "select * from [lm] order by id asc",conn,1,1
		if rs2.recordcount<>0 then
			mbid=rs2("mb")
		end if
		rs2.close:set rs2=nothing
	end if
	rs.close:set rs=nothing
	if mbid="" then mbid=0
	
	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select id,listtum,picw,pich,picx,picy,pictitle,pictitlecolor,pictitlesize,openwindow from [xymb] where id="&mbid&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		listtum=rs("listtum")
		picw=rs("picw")
		pich=rs("pich")
		picx=rs("picx")
		picy=rs("picy")
		pictitle=rs("pictitle")
		pictitlecolor=rs("pictitlecolor")
		pictitlesize=rs("pictitlesize")
		openwindow=rs("openwindow")
		xy=int(picx)*int(picy)
	else
		Response.Write "<BR><BR><BR><center>对不起，系统模版不正确或者没有模版！</center>"
		conn.close:set conn=nothing
		Response.end
	end if
	rs.close:set rs=nothing
	
	if instr(listtum,"$$Piclist$$")=0 then
		Response.Write "<BR><BR><BR><center>对不起，后台系统模版不正确，没有找到$$Piclist$$！</center>"
	else
			 listtum=replace(listtum,"$$Columns$$",lmname)
			 listtum=replace(listtum,"$$Path$$",lmaa())
			 listtum=replace(listtum,"$$LMID$$",lm)
		     listtum=split(listtum,"$$Piclist$$")

		     response.write listtum(0)
		     Response.Write pictulist()
		     Response.Write listtum(1)		
	end if
%>
<!--#include file="foot.asp"-->
<%
conn.close
set conn=nothing
%>