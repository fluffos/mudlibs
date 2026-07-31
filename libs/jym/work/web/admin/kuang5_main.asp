<%@ Language="VBScript" CODEPAGE="936"%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = kuang5_conn.asp -->
<!--#include file = titleb.asp -->
<% 
Response.Buffer = True
'####################################
'#                                  #
'#      ITlearner ASP探针 V1.2      #
'#                                  #
'#     http://www.itlearner.com     #
'#                                  #
'#    转载本段代码时请保留这些信息  #
'#                                  #
'####################################
Dim startime
	 startime=timer()
Dim hx
Set hx = New Cls_AspCheck

class Cls_AspCheck

Public FileName,WebName,WebUrl,SysName,SysNameE,SysVersion

'检查组件是否被支持
Public Function IsObjInstalled(strClassString)
	On Error Resume Next
	Dim xTestObj
	Set xTestObj = Server.CreateObject(strClassString)
	If Err Then
		IsObjInstalled = False
	else	
		IsObjInstalled = True
	end if
	Set xTestObj = Nothing
End Function

'检查组件版本
Public Function getver(Classstr)
	On Error Resume Next
	Dim xTestObj
	Set xTestObj = Server.CreateObject(Classstr)
	If Err Then
		getver=""
	else	
	 	getver=xTestObj.version
	end if
	Set xTestObj = Nothing
End Function

Public Function GetObjInfo(startnum,endnum)
	dim i,Outstr
	for i=startnum to endnum
      	Outstr = Outstr & "<tr><TD align=left>&nbsp;" & theTestObj(i,0) & ""
      	Outstr = Outstr & "<font color=#888888>&nbsp;"&theTestObj(i,1)&"</font>"
      	Outstr = Outstr & "</td>"
    	If Not IsObjInstalled(theTestObj(i,0)) Then 
      	Outstr = Outstr & "<td align=left>&nbsp;<font color=red><b>×</b></font></td>"
    	Else
      	Outstr = Outstr & "<td align=left>&nbsp;<font color=green><b>√</b></font> " & getver(theTestObj(i,0)) & "</td>"
		End If
      	Outstr = Outstr & "</tr>" & vbCrLf
	next
	Response.Write(Outstr)
End Function

Public Function cdrivetype(tnum)
    Select Case tnum
        Case 0: cdrivetype = "未知"
        Case 1: cdrivetype = "可移动磁盘"
        Case 2: cdrivetype = "本地硬盘"
        Case 3: cdrivetype = "网络磁盘"
        Case 4: cdrivetype = "CD-ROM"
        Case 5: cdrivetype = "RAM 磁盘"
    End Select
end function

Private Sub Class_Initialize()
	WebName="IT学习者"
	WebUrl="http://www.itlearner.com"
	SysName="ASP探针"		
	SysNameE="AspCheck"
	SysVersion="V1.2"
	FileName=Request.ServerVariables("SCRIPT_NAME")
End Sub

Public Function dtype(num)
    Select Case num
        Case 0: dtype = "未知"
        Case 1: dtype = "可移动磁盘"
        Case 2: dtype = "本地硬盘"
        Case 3: dtype = "网络磁盘"
        Case 4: dtype = "CD-ROM"
        Case 5: dtype = "RAM 磁盘"
    End Select
End Function

Public Function formatdsize(dsize)
    if dsize>=1073741824 then
		formatdsize=Formatnumber(dsize/1073741824,2) & " GB"
    elseif dsize>=1048576 then
    	formatdsize=Formatnumber(dsize/1048576,2) & " MB"
    elseif dsize>=1024 then
		formatdsize=Formatnumber(dsize/1024,2) & " KB"
	else
		formatdsize=dsize & "B"
	end if
End Function

Public Function formatvariables(str)
on error resume next
str = cstr(server.htmlencode(str))
formatvariables=replace(str,chr(10),"<br>")
End Function

Public Sub ShowFooter()
	dim Endtime,Runtime,OutStr
	Endtime=timer()
	OutStr = "<table border=0 cellpadding=0 cellspacing=1><tr><td align=center>"
	OutStr = OutStr & "<br>"
	OutStr = OutStr & "" & vbcrlf
 	Runtime=FormatNumber((endtime-startime)*1000,2) 
	if Runtime>0 then
		if Runtime>1000 then
		  	OutStr = OutStr & "页面执行时间：约"& FormatNumber(runtime/1000,2) & "秒"
		else
			OutStr = OutStr & "页面执行时间：约"& Runtime & "毫秒"
		end if	
	end if
	OutStr = OutStr & "&nbsp;&nbsp;"
	OutStr = OutStr & ""								
	OutStr = OutStr & "</p></td></tr></table>"
	Response.Write(OutStr)
End Sub
End class

Dim theTestObj(25,1)

	theTestObj(0,0) = "MSWC.AdRotator"
	theTestObj(1,0) = "MSWC.BrowserType"
	theTestObj(2,0) = "MSWC.NextLink"
	theTestObj(3,0) = "MSWC.Tools"
	theTestObj(4,0) = "MSWC.Status"
	theTestObj(5,0) = "MSWC.Counters"
	theTestObj(6,0) = "MSWC.PermissionChecker"
	theTestObj(7,0) = "WScript.Shell"
	theTestObj(8,0) = "Microsoft.XMLHTTP"
	theTestObj(9,0) = "Scripting.FileSystemObject"
	theTestObj(9,1) = "(FSO 文本文件读写)"
	theTestObj(10,0) = "ADODB.Connection"
	theTestObj(10,1) = "(ADO 数据对象)"
    
	theTestObj(11,0) = "SoftArtisans.FileUp"
	theTestObj(11,1) = "(SA-FileUp 文件上传)"
	theTestObj(12,0) = "SoftArtisans.FileManager"
	theTestObj(12,1) = "(SoftArtisans 文件管理)"
	theTestObj(13,0) = "LyfUpload.UploadFile"
	theTestObj(13,1) = "(刘云峰的文件上传组件)"
	theTestObj(14,0) = "Persits.Upload"
	theTestObj(14,1) = "(ASPUpload 文件上传)"
	theTestObj(15,0) = "w3.upload"
	theTestObj(15,1) = "(Dimac 文件上传)"

	theTestObj(16,0) = "JMail.SmtpMail"
	theTestObj(16,1) = "(Dimac JMail 邮件收发)</a>"
	theTestObj(17,0) = "CDONTS.NewMail"
	theTestObj(17,1) = "(虚拟 SMTP 发信)"
	theTestObj(18,0) = "Persits.MailSender"
	theTestObj(18,1) = "(ASPemail 发信)"
	theTestObj(19,0) = "SMTPsvg.Mailer"
	theTestObj(19,1) = "(ASPmail 发信)"
	theTestObj(20,0) = "DkQmail.Qmail"
	theTestObj(20,1) = "(dkQmail 发信)"
	theTestObj(21,0) = "Geocel.Mailer"
	theTestObj(21,1) = "(Geocel 发信)"
	theTestObj(22,0) = "IISmail.Iismail.1"
	theTestObj(22,1) = "(IISmail 发信)"
	theTestObj(23,0) = "SmtpMail.SmtpMail.1"
	theTestObj(23,1) = "(SmtpMail 发信)"
	theTestObj(24,0) = "SoftArtisans.ImageGen"
	theTestObj(24,1) = "(SA 的图像读写组件)"
	theTestObj(25,0) = "W3Image.Image"
	theTestObj(25,1) = "(Dimac 的图像读写组件)"


%>
<HTML>
<HEAD>
<script language=JavaScript>
<!--
if (window.Event)
document.captureEvents(Event.MOUSEUP);
function nocontextmenu()
{
event.cancelBubble = true
event.returnValue = false;
return false;
}
function norightclick(e)
{
if (window.Event)
{
if (e.which == 2 || e.which == 3)
return false;
}
else
if (event.button == 2 || event.button == 3)
{
event.cancelBubble = true
event.returnValue = false;
return false;
}
}
document.oncontextmenu = nocontextmenu; // for IE5+
document.onmousedown = norightclick; // for all others
file:
//-->
</script>
<!--#include file = language.asp -->
<TITLE>kuang5 cms 2.2</TITLE>

<LINK href="admin_style.css" type=text/css rel=StyleSheet>
<SCRIPT language="JavaScript" runat="server">
	function getEngVerJs(){
		try{
			return ScriptEngineMajorVersion() +"."+ScriptEngineMinorVersion()+"."+ ScriptEngineBuildVersion() + " ";
		}catch(e){
			return "服务器不支持此项检测";
		}
		
	}
</SCRIPT>
<SCRIPT language="VBScript" runat="server">
	Function getEngVerVBS()
		getEngVerVBS=ScriptEngineMajorVersion() &"."&ScriptEngineMinorVersion() &"." & ScriptEngineBuildVersion() & " "
	End Function
</SCRIPT>
<script language="javascript">
<!--
function Checksearchbox()
{
if(form1.classname.value == "")
{
	alert("请输入你要检测的组件名！");
	form1.classname.focus();
	return false;
}
}
-->
</SCRIPT>
<style type="text/css">
<!--
.STYLE1 {
	color: #0000FF;
	font-weight: bold;
}
-->
</style>
</HEAD>
<body topmargin=0 leftmargin=0>

<center>
<a name=top></a>
<%
dim action
action=request("action")
if action="testzujian" then
call ObjTest2
end if

Call menu
Call SystemTest
Call CalculateTest
Call showvariable
hx.ShowFooter
Set hx= nothing

%>
<%Sub menu%>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr><th colspan="6">管理后台</th></tr>
		<tr>
<td class=tablerow1>快捷管理链接：</td>
<td class=tablerow1>
  <table border=0 cellspacing=2 cellpadding=2>
  <tr>
  <td><img border=0 src="images/s_.gif" align=absmiddle>&nbsp;<a href="kuang5_mirlist.asp">开区列表</a></td>
  <td><img border=0 src="images/s_.gif" align=absmiddle>&nbsp;<a href="kuang5_news_pl.asp">评论管理</a></td>
  <td><img border=0 src="images/s_.gif" align=absmiddle>&nbsp;<a href="kuang5_tg.asp" class=red2>玩家投稿</a></td>
  <td><img border=0 src="images/s_.gif" align=absmiddle>&nbsp;<a href="kuang5_ly.asp">留言管理</a></td>
    <td><img border=0 src="images/s_.gif" align=absmiddle>&nbsp;<a href="kuang5_stat.asp">数据统计</a></td>
  </tr>
  </table>
</td>
</tr>
		<tre>
<td bgcolor="#ffffff" height=30>&nbsp;系统更新信息：</td>
<td bgcolor="#ffffff"><div id=sys_update><script TYPE="text/javascript" language="javascript" src="http://www.kuang5.com/kuang5cms/adminnews.asp"></script></div></td>
</tr>
</table>
<table border=0><tr><td height=3></td></tr></table>
<%End Sub%>
<%Sub SystemTest
on error resume next
%>
<a name="SystemTest"></a> 
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
        <tr class="tr">
          <th colspan="4">服务器有关参数</th>
        </tr>
        <tr class="tr"> 
          <td class=tablerow width="130">&nbsp;服务器名</td>
          <td class=tablerow width="170">&nbsp;<%=Request.ServerVariables("SERVER_NAME")%></td>
          <td class=tablerow width="130">&nbsp;服务器操作系统</td>
          <td class=tablerow width="170">&nbsp;<%=Request.ServerVariables("OS")%></td>
        </tr>
        <tr class="tr"> 
          <td class=tablerow>&nbsp;服务器IP</td>
          <td class=tablerow>&nbsp;<%=Request.ServerVariables("LOCAL_ADDR")%></td>
          <td class=tablerow>&nbsp;服务器端口</td>
          <td class=tablerow>&nbsp;<%=Request.ServerVariables("SERVER_PORT")%></td>
        </tr><tr class="tr"> <td class=tablerow>&nbsp;服务器时间</td>
          <td class=tablerow>&nbsp;<%=now%></td>
          <td class=tablerow>&nbsp;服务器CPU数量</td>
          <td class=tablerow>&nbsp;<%=Request.ServerVariables("NUMBER_OF_PROCESSORS")%> 
            个</td>
        </tr><tr class="tr"> <td class=tablerow>&nbsp;IIS版本</td>
          <td class=tablerow>&nbsp;<%=Request.ServerVariables("SERVER_SOFTWARE")%></td>
          <td class=tablerow>&nbsp;脚本超时时间</td>
          <td class=tablerow>&nbsp;<%=Server.ScriptTimeout%> 秒</td>
        </tr><tr class="tr"> <td class=tablerow>&nbsp;Application变量</td>
          <td class=tablerow>&nbsp;<%Response.Write(Application.Contents.Count & "个 ")
		  if Application.Contents.count>0 then Response.Write("[<a href=""?action=showapp"">遍历Application变量</a>]")%>          </td>
          <td class=tablerow>&nbsp;Session变量<br> </td>
          <td class=tablerow>&nbsp;<%Response.Write(Session.Contents.Count&"个 ")
		  if Session.Contents.count>0 then Response.Write("[<a href=""?action=showsession"">遍历Session变量</a>]")%>          </td>
        </tr><tr class="tr"> <td class=tablerow>&nbsp;<a href="?action=showvariables">所有服务器参数</a></td>
          <td class=tablerow>&nbsp;<%Response.Write(Request.ServerVariables.Count&"个 ")
		  if Request.ServerVariables.Count>0 then Response.Write("[<a href=""?action=showvariables"">遍历服务器参数</a>]")%>          </td>
          <td class=tablerow>&nbsp;服务器环境变量</td>
          <td class=tablerow>&nbsp;<%
			dim WshShell,WshSysEnv
			Set WshShell = server.CreateObject("WScript.Shell")
			Set WshSysEnv = WshShell.Environment
			if err then
				Response.Write("服务器不支持WScript.Shell组件")
				err.clear
			else
				Response.Write(WshSysEnv.count &"个 ")
				if WshSysEnv.count>0 then Response.Write("[<a href=""?action=showwsh"">遍历环境变量</a>]") 
		 	end if
		  %>		  </td>
        </tr><tr class="tr"> <td class=tablerow align=left>&nbsp;服务器解译引擎</td>
          <td class=tablerow colspan="3">&nbsp;JScript: <%= getEngVerJs() %> | VBScript: <%=getEngVerVBS()%></td>
        </tr><tr class="tr"> <td class=tablerow align=left bgcolor="#FFFFFF">&nbsp;本文件实际路径</td>
          <td class=tablerow height="8" colspan="3" bgcolor="#FFFFFF">&nbsp;<%=server.mappath(Request.ServerVariables("SCRIPT_NAME"))%></td>
        </tr>
      </table>
      <%
if action="showapp" or action="showsession" or action="showvariables" or action="showwsh" then
	showvariable(action)
end if
%>
<table border=0><tr><td height=3></td></tr></table>
<%
End Sub



Sub ObjTest2
	Dim strClass
    strClass = Trim(Request.Form("classname"))
    If strClass <> "" then
	
    Response.Write "<br>您指定的组件的检查结果："
      If Not hx.IsObjInstalled(strClass) then 
        Response.Write "<br><font color=red>很遗憾，该服务器不支持" & strclass & "组件！</font>"
      Else
        Response.Write "<br><font color=green>"
		Response.Write " 恭喜！该服务器支持" & strclass & "组件。"
		If hx.getver(strclass)<>"" then
		Response.Write " 该组件版本是：" & hx.getver(strclass)
		End if
		Response.Write "</font>"
      End If
      Response.Write "<br>"
    end if
	
	Response.Write "<p><a href="&hx.FileName&">返回</a></p>"
	Response.End
End Sub
Sub CalculateTest
%><a name="CalcuateTest"></a>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr>
			<th width="349" align="center">
			文章阅读前十名</th>
			<th width="349" align="center">
			文章阅读后十名</th>
		</tr>
		<tr>
			<td class=tablerow width="349">
<%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select top 10 * from [news]  order by hit desc , id desc",conn,1,1
while not rs.eof
  Response.Write "　·<a href=../news_view.asp?newsid="&rs("id")&" target=_blank><font color=999999>"&titleb(rs("title"),30)&"</font></a><font color=999999>("&rs("hit")&"次)</font><BR>"
rs.movenext
wend
%>
			</td>
			<td class=tablerow width="349">
<%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select top 10 * from [news] order by hit asc , id desc",conn,1,1
while not rs.eof
  Response.Write "　·<a href=../news_view.asp?newsid="&rs("id")&" target=_blank><font color=999999>"&titleb(rs("title"),30)&"</font></a><font color=999999>("&rs("hit")&"次)</font><BR>"
rs.movenext
wend
%></td>
		</tr>
</table>
<%End Sub%>
</center>
</BODY>
</HTML>
