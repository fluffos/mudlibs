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
%>
<!--#include file = kuang5_conn.asp -->
<%
'=================================
'   狂舞游戏网站管理系统
'   www.kuang5.com
'  copyright(c)2007-2009 狂舞网络
'=================================
%>

<table width="98%" border="0" cellpadding="5" cellspacing="1" >
  <tr >
    <td><table border="0" width="100%" style="LINE-HEIGHT: 14pt">
      <tr>
        <td align="right" width="110" class="ftd"><b>注意事宜</b></td>
        <td width="20"> </td>
        <td><b>注</b>：如果发生无法下载的情况，那是因为该服务器下载人数已经达到最高限制人数，请换一个服务器下载或稍后下载.<br>
          下载工具：迅雷 网际快车 网络蚂蚁 影音传送带</td>
      </tr>
    </table></td>
  </tr>
</table>
      <br>
<%




  sql="select * from [downlist]"

if id<>"" then sql=sql&" where id="&clng(id)
sql=sql&" order by id desc"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
while not rs.eof
  downname=rs("downname")
  downsize=rs("downsize")
  pic=rs("pic")
  sm=rs("sm")
  dz1=rs("dz1")
  dz2=rs("dz2")
  addtime=rs("addtime")
  %>



      <table width='98%' border='0' cellpadding='5' cellspacing='1'>
        <tr>
          <td width='148' align='center'><img src='<%=pic%>' width=148 height=112></td>
          <td valign='top'><table width='100%' border='0' cellpadding='4' cellspacing='1'>
              <tr>
                <td width="49%" height='30' class=ftd red>&nbsp;<STRONG><%=downname%></STRONG></td>
                <td width=24% class=STYLE9>&nbsp;大小：<%=downsize%></td>
                <td width=27% class=STYLE9>&nbsp;时间:<%=addtime%></td>
              </tr>
              <tr>
                <td height=48 colspan=3 valign=top class=ftd STYLE9><span class="STYLE9">&nbsp;<%=sm%></span></td>
            </tr>
              <tr>
                <td height='30' colspan=3 class=ftd STYLE9>&nbsp;下载地址:&nbsp;&nbsp;<a href='<%=dz1%>' target=_blank>本站下载</a>&nbsp;&nbsp;<a href='<%=dz2%>' target=_blank>其他下载</a></td>
              </tr>
          </table></td>
        </tr>
</table>
      <br>
      
<%
rs.movenext
wend

rs.close
set rs=nothing
%>

<%
end function

	set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open "select * from [lm] where id="&lm&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		mbid=rs("mb")
		lmname="游戏下载"
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
	rs.Open "select id,listtum from [xymb] where id="&mbid&" order by id desc",conn,1,1
	if rs.recordcount<>0 then
		listtum=rs("listtum")
	else
		Response.Write "<BR><BR><BR><center>对不起，系统不正确或者没有！</center>"
		conn.close:set conn=nothing
		Response.end
	end if
	rs.close:set rs=nothing
	
	if instr(listtum,"$$Piclist$$")=0 then
		Response.Write "<BR><BR><BR><center>对不起，后台系统不正确，没有找到！</center>"
	else
			 listtum=replace(listtum,"$$kefu$$",kefu)	
			 listtum=replace(listtum,"$$Columns$$","游戏下载")
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