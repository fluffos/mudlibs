<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
			<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
			<HTML>
			<HEAD>
			<TITLE>调查结果</TITLE>
			<META http-equiv=Content-Type content="text/html; charset=gb2312">
			<style type="text/css">
<!--
.style2 {	FONT-SIZE: 11pt; COLOR: #cc0000
}
TD {
	FONT-SIZE: 9pt; LINE-HEIGHT: 1.5
}
BODY {
	FONT-SIZE: 9pt; LINE-HEIGHT: 1.5
}
A:link {
	FONT-SIZE: 9pt; COLOR: #000000; TEXT-DECORATION: underline
}
A:visited {
	FONT-SIZE: 9pt; COLOR: #000000; TEXT-DECORATION: underline
}
A:hover {
	FONT-SIZE: 9pt; COLOR: red
}
.m1 {
	BORDER-TOP: #dfdfdb 1px solid; BORDER-LEFT: #dfdfdb 1px solid; BORDER-BOTTOM: #808080 1px solid
}
.m2 {
	BORDER-RIGHT: #dfdfdb 1px solid; BORDER-TOP: #dfdfdb 1px solid; BORDER-LEFT: #dfdfdb 1px solid; BORDER-BOTTOM: #808080 1px solid
}
.m3 {
	BORDER-RIGHT: #dfdfdb 1px solid; BORDER-TOP: #dfdfdb 1px solid; BORDER-LEFT: #dfdfdb 1px solid
}
.article {
	FONT-SIZE: 10pt; WORD-BREAK: break-all
}
.bn {
	FONT-SIZE: 0.1pt; COLOR: #ffffff; LINE-HEIGHT: 50%
}
.contents {
	FONT-SIZE: 1pt; COLOR: #f7f6f8
}
.nb {
	BORDER-RIGHT: #000000 1px solid; BORDER-TOP: #000000 1px solid; BORDER-LEFT: #000000 1px solid; BORDER-BOTTOM: #000000 1px solid; HEIGHT: 18px
}
.coolbg {
	BORDER-RIGHT: #acacac 2px solid; BORDER-BOTTOM: #acacac 2px solid; BACKGROUND-COLOR: #e6e6e6
}

-->
            </style>
			</HEAD>
			<BODY leftmargin="0" topmargin="0" marginwidth="0" marginheight="0">
<%
tpid=trim(Request("tpid"))
tps=trim(Request("tps"))
tps=replace(tps," ","")
if (not isNumeric(tpid)) then
  Response.Write "<Script Language=JavaScript>alert('ＩＤ参数错误或有非法字符或没指定参数，请勿随意提交数据！');</Script>"
  response.end  
end if

aaa=split(tps,",")

if Request.Cookies("tpid"&tpid&"")=tpid then
	Response.Write "<BR><BR><BR><center>已经投过了，请不要重复投票！"
	er=1
end if

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [tp] where id="&tpid&" order by id desc",conn,1,1
if rs.recordcount<>0 then
	endtime=rs("endtime")
	title=rs("title")
end if
rs.close:set rs=nothing


if datediff("d",endtime,date())>0 then
	Response.Write "已经到期了，不能再投票了"
	er=1
end if

if er<>1 then

		for i=0 to ubound(aaa)
			tpsid=aaa(i)
			'Response.Write tpsid&"<BR>"
			conn.Execute "update [tptitle] set [tps]=tps+1 where id="&clng(tpsid)
			Response.Cookies ("tpid"&tpid&"")=tpid
			Response.Cookies("tpid"&tpid&"").expires=date+1
		next

end if
%>
            <table width="600" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
				<tr> 
					<td valign="top">
			
						<table width="600" border="0" align="center" cellpadding="2" cellspacing="0" class="border">
							<tr class="title"> 
								<td height="35" colspan="3"><strong><IMG height=46 src="images/vote.gif" width=320></strong></td>
							</tr>
							<tr class="tdbg">
								<td>
									<table width="600" border="0" align="center" cellpadding="0" cellspacing="2">
										<tr>
										  <td colspan="3" align="right" bgcolor="#cccc99" height="6"></td>
									  </tr>
										<tr> 
										  <td width="140" align="right" bgcolor="#dfeae4"><div align="center"><strong>调查内容：</strong></div></td>
											<td colspan="2" bgcolor="#dfeae4"><%=title%>(过期时间：<%=endtime%>)</td>
										</tr>
										<tr> 
											<td colspan="3" align="center">&nbsp;</td>
										</tr>
										<tr> 
											<td width="140" align="center"><strong>投票选项</strong></td>
											<td width="64" align="right"><div align="center"><strong>票数</strong></div></td>
											<td width="388" align="center"><strong>百分比</strong></td>
										</tr>
<%
set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [tptitle] where tpid="&tpid&" order by id desc",conn,1,1
if rs.recordcount<>0 then


set rssum = Server.CreateObject("ADODB.RecordSet")
rssum.Open "select sum(tps) as f_sum from [tptitle] where tpid="&tpid&" ",conn,1,1
tpsall=rssum(0)
rssum.close:set rssum=nothing

for i=1 to rs.recordcount
tps=rs("tps")

if tpsall<>0 then
	bfb=Round(rs("tps")/tpsall*100,2)
else
	bfb=0
end if
%>
										<tr> 
											<td height="25" style="BORDER-BOTTOM: 1px solid" width="140" align="right"><div align="center"><font color="#ff6600"><%=rs("tpxx")%></font> </div></td>
											<td  style="BORDER-BOTTOM: 1px solid" align="right"> 
			<div align="center"><%=tps%>
			</div></td>
											<td  style="BORDER-BOTTOM: 1px solid"> 
			<img src='images/tp_bg.gif' width='<%=int(bfb)%>' height='15' align='absmiddle'>&nbsp;<%=bfb%>%											</td>
										</tr>
										<%
rs.movenext
if rs.eof then exit for
next
end if
rs.close:set rs=nothing
conn.close:set conn=nothing
%>
									</table></td>
							</tr>
						</table>
				  </td>
				</tr>
				<tr>
				  <td  bgcolor="#cccc99" height="6"></td>
			  </tr>
			  <tr>
				  <td><p align="center">【<a href="javascript:window.close();">关闭窗口</a>】<br>
			<br></p></td>
			  </tr>
			  
			</table>
			</BODY></HTML>
			