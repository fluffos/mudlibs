<%@ Language="VBScript" CODEPAGE="936"%>
<% Option Explicit %>
<% 
Response.Buffer = True
'####################################
'#                                  #
'#      ITlearner ASP探针 V1.3      #
'#                                  #
'#     http://www.itlearner.com     #
'#                                  #
'#  转载本探针程序时请保留这些信息  #
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
	      	Outstr = Outstr & "<tr class=tr align=center><td class=TableRow>" & theTestObj(i,0) & ""
	      	if theTestObj(i,1) <> "" then Outstr = Outstr & "<span class=""font_1"">"&theTestObj(i,1)&"</span>"
	      	Outstr = Outstr & "</td>"
	    	If Not IsObjInstalled(theTestObj(i,0)) Then 
	      	Outstr = Outstr & "<td class=TableRow><span class=""font_2""><b>×</b></span></td>"
	    	Else
	      	Outstr = Outstr & "<td class=TableRow><span class=""font_3""><b>√</b></span> " & getver(theTestObj(i,0)) & "</td>"
			End If
	      	Outstr = Outstr & "</tr>" & vbCrLf
		next
		Response.Write(Outstr)
	End Function

	Private Sub Class_Initialize()
		WebName="狂舞网"
		WebUrl="http://www.kuang5.com"
		SysName="狂舞网"		
		SysNameE="AspCheck"
		SysVersion="V1.3"
		FileName=Request.ServerVariables("SCRIPT_NAME")
		if InStr(FileName,"/") then FileName = right(FileName,len(FileName)-InStrRev(FileName,"/"))
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


	
	Public Function getEngVerVBS()
		getEngVerVBS=ScriptEngineMajorVersion() &"."&ScriptEngineMinorVersion() &"." & ScriptEngineBuildVersion() & " "
	End Function
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
	theTestObj(12,0) = "SoftArtisans.ImageGen"
	theTestObj(12,1) = "(SA 的图像读写组件)"
	theTestObj(13,0) = "LyfUpload.UploadFile"
	theTestObj(13,1) = "(刘云峰的文件上传组件)"
	theTestObj(14,0) = "Persits.Upload"
	theTestObj(14,1) = "(ASPUpload 文件上传)"
	theTestObj(15,0) = "w3.upload"
	theTestObj(15,1) = "(Dimac 文件上传)"
	theTestObj(16,0) = "JMail.SmtpMail"
	theTestObj(16,1) = "(Dimac JMail 邮件收发)"
	theTestObj(17,0) = "CDONTS.NewMail"
	theTestObj(17,1) = "(虚拟 SMTP 发信)"
	theTestObj(18,0) = "Persits.MailSender"
	theTestObj(18,1) = "(ASPemail 发信)"
	theTestObj(19,0) = "SmtpMail.SmtpMail.1"
	theTestObj(19,1) = "(SmtpMail 发信)"
	theTestObj(20,0) = "PE_Common.Site"
	theTestObj(20,1) = "(动易2005组件)"	
%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>IT学习者ASP探针(ITlearner AspCheck) </title>
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
<style>
<!--

.PicBar { background-color: #0099CF; border: 1px solid #000000; height: 12px;}

-->
</STYLE>
<script language="JavaScript" runat="server">
	function getEngVerJs(){
		try{
			return ScriptEngineMajorVersion() +"."+ScriptEngineMinorVersion()+"."+ ScriptEngineBuildVersion() + " ";
		}catch(e){
			return "服务器不支持此项检测";
		}
		
	}
</script>
<script language="JavaScript" type="text/javascript">
<!--
function Checksearchbox(form1){
if(form1.classname.value == "")
{
	alert("请输入你要检测的组件名！");
	form1.classname.focus();
	return false;
}
}
-->
</script>
</head>
<body topmargin=0 leftmargin=0>
<a name="top"></a>

<%
dim action
action=request("action")
select case action
case "Custom_ObjInfo"
	Call menu2
%><div class="frame_box"><%Call Custom_ObjInfo%></div>
<%Response.End
case "SystemCheck"
	Call menu2
	Call SystemCheck
end select

Call menu
Call SystemTest
Call ObjTest
Call CalculateTest
Call DriveTest
Call SpeedTest

%>
<%Sub menu%>
<center>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr><th>服务器情况选项：</th></tr>
<tr bgcolor="#FFFFFF"><td class=TableRow>
  <table border=0>
  <tr>
  <td class=TableRow><img border=0 src="images/s.gif" align=absmiddle><a href="#SystemTest" class=h_p_bar>服务器有关参数</a>&nbsp;</td>
  <td class=TableRow><img border=0 src="images/s.gif" align=absmiddle><a href="#ObjTest" class=h_p_bar>服务器组件情况</a>&nbsp;</td>
  <td class=TableRow><img border=0 src="images/s.gif" align=absmiddle><a href="#CalcuateTest" class=h_p_bar>服务器运算能力</a>&nbsp;</td>
  <td class=TableRow><img border=0 src="images/s.gif" align=absmiddle><a href="#DriveTest" class=h_p_bar>服务器磁盘信息</a>&nbsp;</td>
  <td class=TableRow><img border=0 src="images/s.gif" align=absmiddle><a href="#SpeedTest" class=h_p_bar>服务器连接速度</a>&nbsp;</td>
  <td class=TableRow><img border=0 src="images/s.gif" align=absmiddle>安全：<a href="?action=SystemCheck" class=h_p_bar>系统用户(组)和进程检测</a>&nbsp;</td>
  </tr>
  </table>
</td></tr>
</table><br>
<%End Sub
Sub menu2
  Response.Write "<table width=98% align=center border=0 cellspacing=1 cellpadding=2 class=tableBorder>"
  Response.Write "<tr><td class=TableRow class=td>服务器情况选项：</td></tr>"
  Response.Write "<tr class=tr><td class=TableRow>"
  Response.Write "<table border=0>"
  Response.Write "<tr>"
  Response.Write "<td class=TableRow><img border=0 src='images/s.gif' align=absmiddle>"
  Response.Write "<a href="""&hx.FileName&""">返回主界面</a>"
  Response.Write " &nbsp;</td>"
  Response.Write " </tr>"
  Response.Write "</table>"
  Response.Write "</td></tr>"
  Response.Write "</table>"
End Sub
Sub GoTop
	Response.Write " <a href=""#top"" title=""返回顶部""><font face=""Webdings"">5</font></a>"
End Sub
%>
<%Sub smenu(i)%>
	<font face="Wingdings"><span class="item_title_other" onClick="showsubmenu(<%=i%>)" id="txt<%=i%>"><span title="关闭此项">x</span></span></font>
<%End Sub%>
<%Sub SystemTest
on error resume next
%>
<a name="SystemTest"></a> 

<div class="frame_box">

	<div class="item_content" id='submenu0'>
		<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
		<tr><th colspan=4>&nbsp服务器有关参数</th></tr>
        <tr align=center>
          <td class=TableRow width="110">服务器名</td>
          <td class=TableRow width="185"><%=Request.ServerVariables("SERVER_NAME")%></td>
          <td class=TableRow width="110">服务器操作系统</td>
          <td class=TableRow width="185"><%=Request.ServerVariables("OS")%></td>
        </tr>
        <tr align=center>
          <td class=TableRow>服务器IP</td>
          <td class=TableRow><%=Request.ServerVariables("LOCAL_ADDR")%></td>
          <td class=TableRow>服务器端口</td>
          <td class=TableRow><%=Request.ServerVariables("SERVER_PORT")%></td>
        </tr>
        <tr class=tr align=center>
          <td class=TableRow>服务器时间</td>
          <td class=TableRow><%=now%></td>
          <td class=TableRow>服务器CPU数量</td>
          <td class=TableRow><%=Request.ServerVariables("NUMBER_OF_PROCESSORS")%> 
            个</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>IIS版本</td>
          <td class=TableRow><%=Request.ServerVariables("SERVER_SOFTWARE")%></td>
          <td class=TableRow>脚本超时时间</td>
          <td class=TableRow><%=Server.ScriptTimeout%> 秒</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>Application变量</td>
          <td class=TableRow><%Response.Write(Application.Contents.Count & "个 ")
		  if Application.Contents.count>0 then Response.Write("[<a href=""?action=showapp"">遍历Application变量</a>]")%>
          </td>
          <td class=TableRow>Session变量</td>
          <td class=TableRow><%Response.Write(Session.Contents.Count&"个 ")
		  if Session.Contents.count>0 then Response.Write("[<a href=""?action=showsession"">遍历Session变量</a>]")%>
          </td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow><a href="?action=showvariables">所有服务器参数</a></td>
          <td class=TableRow><%Response.Write(Request.ServerVariables.Count&"个 ")
		  if Request.ServerVariables.Count>0 then Response.Write("[<a href=""?action=showvariables"">遍历服务器参数</a>]")%>
          </td>
          <td class=TableRow>服务器环境变量</td>
          <td class=TableRow><%
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
		  %>		  
          </td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>服务器解译引擎</td>
          <td class=TableRow colspan="3">JScript: <%= getEngVerJs() %> | VBScript: <%=hx.getEngVerVBS()%></td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>本文件实际路径</td>
          <td class=TableRow colspan="3"><%=server.mappath(Request.ServerVariables("SCRIPT_NAME"))%></td>
        </tr>
      </table>
      <%
if action="showapp" or action="showsession" or action="showvariables" or action="showwsh" then
	showvariable(action)
end if
%>
	</div>
</div>
<br>
<%
End Sub

Sub showvariable(action)
%>
<table width="100%" border="0" cellpadding="3" cellspacing="1" bgcolor="#0099CC">
          <tr class=tr align=center> 
    <td class=TableRow colspan="2">
      <%
	'on error resume next
	dim Item,xTestObj,outstr
		Response.Write("&nbsp")
	if action="showapp" then
		Response.Write("遍历Application变量")
		set xTestObj=Application.Contents
	elseif action="showsession" then
		Response.Write("遍历Session变量")
		set xTestObj=Session.Contents
	elseif action="showvariables" then
		Response.Write("遍历服务器参数")
		set xTestObj=Request.ServerVariables
	elseif action="showwsh" then
		Response.Write("遍历环境变量")
		dim WshShell
		Set WshShell = server.CreateObject("WScript.Shell")
		set xTestObj=WshShell.Environment
	end if
		Response.Write "(<a href="""&hx.FileName&""">关闭</a>)"
	%>
    </td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td class=TableRow width="125">变量名</td>
    <td class=TableRow width="470">值</td>
  </tr>
  <%
	if err then
		outstr = "<tr bgcolor=""#FFFFFF""><td class=TableRow colspan=""2"">没有符合条件的变量</td></tr>"
		err.clear
	else
		dim w
		if action="showwsh" then
			for each Item in xTestObj
				w=split(Item,"=")
				outstr = outstr & "<tr bgcolor=""#FFFFFF"">"
				outstr = outstr & "<td class=TableRow>" & w(0) & "</td>" 
				outstr = outstr & "<td class=TableRow>" & w(1) & "</td>" 
				outstr = outstr & "</tr>" 		
			next
		else
			dim i
			for each Item in xTestObj
				outstr = outstr & "<tr bgcolor=""#FFFFFF"">"
				outstr = outstr & "<td class=TableRow>" & Item & "</td>" 	
				outstr = outstr & "<td class=TableRow>" 
				if IsArray(xTestObj(Item)) then		
					for i=0 to ubound(xTestObj(Item))-1
						if IsArray(xTestObj(Item)(i)) then
						outstr = outstr & "数组" & "<br>"					
						else
						outstr = outstr & hx.formatvariables(xTestObj(Item)(i)) & "<br>"
						end if
					next
				else
					outstr = outstr & hx.formatvariables(xTestObj(Item))
				end if	
				outstr = outstr & "</td>"
				outstr = outstr & "</tr>" 
			next
		end if
	end if
		Response.Write(outstr)	
		set xTestObj=nothing
		%>
</table>
<%End Sub%>
<%Sub ObjTest%>
<a name="ObjTest"></a>
	 <table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr align=center>
<th width="50%" class=s>IIS自带的ASP组件支持情况</th>
<th width="50%" class=s>网站常用组件支持情况</th>
</tr>
<tr>
<td class=TableRow>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="TableBorder2">
        <tr class=tr align=center> 
          <td class=TableRow width="450">组 件 名 称</td>
          <td class=TableRow width="150">支持及版本</td>
        </tr>
        <%hx.GetObjInfo 0,10%>
      </table>
</td>
<td class=TableRow valign="top">
 <table cellspacing=1 cellpadding=2 class=tables>
        <tr class=tr align=center> 
          <td class=TableRow width="450">组 件 名 称</td>
          <td class=TableRow width="150">支持及版本</td>
        </tr>
        <%hx.GetObjInfo 11,20%>
      </table>
</td>
</tr>

</table> 
<br>
      <%Call Custom_ObjInfo()%>
<%
End Sub
Sub Custom_ObjInfo%>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
				        <tr class=td> 
          <td class=TableRow>&nbsp其他组件支持情况检测 </td>
        </tr>        
        <tr class=tr align=center> 
          <td class=TableRow height="30" bgcolor="#FFFFFF">
          <form action="?action=Custom_ObjInfo" method="post">            
          输入你要检测的组件的ProgId或ClassId 
              <input class="txt" type="text" value="" name="classname" size="40"> 
              <input type="submit" value="确定" class="btn" name="submit1" onClick="return Checksearchbox(this.form);">
          </form> 
          </td>
				</tr>
<%
		Dim strClass
    strClass = Trim(Request.Form("classname"))
    If strClass <> "" then
	
    Response.Write "<tr><td class=TableRow height=""30"" bgcolor=""#FFFFFF"">您指定的组件的检查结果："
      If Not hx.IsObjInstalled(strClass) then 
        Response.Write "<span class=""font_3"">很遗憾，该服务器不支持" & strclass & "组件！</span>"
      Else
        Response.Write "<span class=""font_3"">"
		Response.Write " 恭喜！该服务器支持" & strclass & "组件。"
		If hx.getver(strclass)<>"" then
		Response.Write " 该组件版本是：" & hx.getver(strclass)
		End if
		Response.Write "</span>"
      End If
      Response.Write "</td></tr>"  
    end if
%>
      </table>
<%End Sub

Sub CalculateTest
%><a name="CalcuateTest"></a>
<div class="frame_box">
	<div class="item_content" id='submenu2'>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
                <tr> 
          <th colspan="3">&nbsp服务器运算能力:  让服务器执行50万次加法(整数运算)和20万次开方(浮点运算)，记录其所使用的时间。 
          </th>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow width="400">可 供 参 考 的 服 务 器 列 表</td>
          <td class=TableRow width="100">整数运算</td>
          <td class=TableRow width="100">浮点运算</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>ITlearner的电脑&nbsp;　(CPU:Celeron 2G&nbsp; 内存:512M)</td>
          <td class=TableRow>242.19 毫秒</td>
          <td class=TableRow>191.41 毫秒</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>ITlearner的服务器&nbsp;(CPU:P4 3.0G(1M) 内存:1.5G)</td>
          <td class=TableRow>187.50 毫秒</td>
          <td class=TableRow>171.88 毫秒</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow><a href="http://union.itlearner.com" target="_blank">中国频道虚拟主机</a>&nbsp; [2005/08/08]</td>
          <td class=TableRow>375.00 毫秒</td>
          <td class=TableRow>328.13 毫秒</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow><a href="http://flash.itlearner.com" target="_blank">东南数据虚拟主机</a>&nbsp; [2005/08/08]</td>
          <td class=TableRow>343.75 毫秒</td>
          <td class=TableRow>312.50 毫秒</td>  	
        </tr> 
        <tr class=tr align=center> 
          <td class=TableRow><a href="http://www.iva.cn" target="_blank">伊瓦科技虚拟主机</a>&nbsp; [2005/08/08]</td>
          <td class=TableRow>203.13 毫秒</td>
          <td class=TableRow>187.50 毫秒</td>  	
        </tr>                          
        <%
	dim i,t1,t2,tempvalue,runtime1,runtime2
	'开始计算50万次加法所需时间
	t1=timer()
	for i=1 to 500000
		tempvalue= 1 + 1
	next
	t2=timer()
	runtime1=formatnumber((t2-t1)*1000,2)
	
	'开始计算20万次开方所需时间
	t1=timer()
	for i=1 to 200000
		tempvalue= 2^0.5
	next
	t2=timer()
	runtime2=formatnumber((t2-t1)*1000,2)
%>
        <tr class=tr align=center> 
          <td class=TableRow><span class="font_3">您正在使用的这台服务器</span>&nbsp; <input name="button" type="button" class="btn" onClick="document.location.href='<%=hx.FileName%>'" value="重新测试"> 
          </td>
          <td class=TableRow><span class="font_3"><%=runtime1%> 毫秒</span></td>
          <td class=TableRow><span class="font_3"><%=runtime2%> 毫秒</span></td>
        </tr>
      </table>
	</div>
</div>
<br>
<%
End Sub
Sub DriveTest
	On Error Resume Next
	Dim fo,d,xTestObj
	set fo=Server.Createobject("Scripting.FileSystemObject")
	set xTestObj=fo.Drives
%>
<a name="DriveTest"></a>
<div class="frame_box">
	<div class="item_content" id='submenu4'>
		<%if hx.IsObjInstalled("Scripting.FileSystemObject") then%>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
                <tr class=td> 
          <th colspan="7">&nbsp服务器磁盘信息</th>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow width="90">磁盘类型</td>
          <td class=TableRow width="35">盘符</td>
          <td class=TableRow width="35">可用</td>
          <td class=TableRow width="100">卷标</td>
          <td class=TableRow width="80">文件系统</td>
          <td class=TableRow width="130">可用空间</td>
		  <td class=TableRow width="130">总空间</td>
        </tr>
		<%
	for each d in xTestObj
		Response.write "<tr class=""tr"">"
		Response.write "<td class=TableRow>"&hx.dtype(d.DriveType)&"</td>"
		Response.write "<td class=TableRow>"&d.DriveLetter&"</td>"		
		if d.DriveLetter = "A" then
		Response.Write "<td class=TableRow colspan=""5"">为防止影响服务器，不检查软驱</td>"
		else
		Response.write "<td class=TableRow>"
		if d.isready then
			Response.Write "√"
			Response.write "</td>"
			Response.write "<td class=TableRow>"&d.VolumeName&"</td>"
			Response.write "<td class=TableRow>"&d.FileSystem&"</td>"	
			Response.write "<td class=TableRow>"&hx.formatdsize(d.FreeSpace)&"</td>"
			Response.write "<td class=TableRow>"&hx.formatdsize(d.TotalSize)&"</td>"
		else
			Response.Write "×"
			Response.Write "<td class=TableRow colspan=4>&nbsp;可能是磁盘有问题，或者程序没有读取权限</td>"			
		end if			 
		end if		 
	next%>
      </table><br>
	  <%
	Dim filePath,fileDir,fileDrive
	filePath = server.MapPath(".")
	set fileDir = fo.GetFolder(filePath)
	set fileDrive = fo.GetDrive(fileDir.Drive)
	  %>
      <table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
                <tr class=td> 
          <th colspan="6">&nbsp当前文件夹信息 (<%=filePath%>)</th>
        </tr>
        <tr class="tr"> 
          <td class=TableRow width="100">已用空间</td>
          <td class=TableRow width="100">可用空间</td>
          <td class=TableRow width="70">文件夹数</td>
          <td class=TableRow width="70">文件数</td>
          <td class=TableRow width="130">创建时间</td>
          <td class=TableRow width="130">修改时间</td>
        </tr>
        <%
		Response.write "<tr class=""tr"">"
		Response.write "<td class=TableRow>"&hx.formatdsize(fileDir.Size)&"</td>"
		Response.write "<td class=TableRow>"
		Response.write hx.formatdsize(fileDrive.AvailableSpace)
		if err then
		Response.write "没有权限读取"
		error.clear
		end if
		Response.write "</td>"
		Response.write "<td class=TableRow>"&fileDir.SubFolders.Count&"</td>"
		Response.write "<td class=TableRow>"&fileDir.Files.Count&"</td>"						
		Response.write "<td class=TableRow>"&fileDir.DateCreated&"</td> "
		Response.write "<td class=TableRow>"&fileDir.DateLastModified&"</td> "
	
	Dim i,t1,t2,runtime,TestFileName
	Dim tempfo
	t1= timer()
	TestFileName=server.mappath("ITlearner_Test.txt")
	for i=1 to 30
	set tempfo=fo.CreateTextFile(TestFileName,true)
		tempfo.WriteLine "It's a test file."
	set tempfo=nothing
	set tempfo=fo.OpenTextFile(TestFileName,8,0)
		tempfo.WriteLine "It's a test file."
	set tempfo=nothing
	set tempfo=fo.GetFile(TestFileName)
		tempfo.delete True
	set tempfo=nothing	
	next
	t2=	timer()
	runtime=formatnumber((t2-t1)*1000,2)		 
%>
      </table><br>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
                <tr class=td> 
          <th colspan="2">&nbsp磁盘文件操作速度测试 (重复创建、写入、追加和删除文本文件30次，记录其所使用的时间)</th>
        </tr>
        <tr class="tr"> 
          <td class=TableRow width="400">可 供 参 考 的 服 务 器 列 表</td>
          <td class=TableRow width="200">完成时间</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>ITlearner的电脑&nbsp;　(CPU:Celeron 2G&nbsp; 内存:512M)</td>
          <td class=TableRow>203.13 ~ 250.00 毫秒</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>ITlearner的服务器&nbsp;(CPU:P4 3.0G(1M) 内存:1.5G)</td>
          <td class=TableRow>140.63 ~ 157.23 毫秒</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>中国频道虚拟主机&nbsp; [2005/08/08]</td>
          <td class=TableRow>656.25 ~ 718.75 毫秒</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>东南数据虚拟主机&nbsp; [2005/08/08]</td>
          <td class=TableRow>500.25 ~ 578.13 毫秒</td>
        </tr>        
        <tr class=tr align=center> 
          <td class=TableRow><span class="font_3">您正在使用的这台服务器</span>&nbsp; <input name="button2" type="button" class=btn onClick="document.location.href='<%=hx.FileName%>'" value="重新测试"> 
          </td>
          <td class=TableRow><span class="font_3"><%=runtime%> 毫秒</span></td>
        </tr>
      </table>
      <%
	  	else
		Response.write "&nbsp;您的服务器或租用的空间不支持FSO组件，无法进行此项测试!"
	end if%>
	</div>
</div>
<br>
<%
End Sub
Sub SpeedTest
Response.Flush()
%>
<a name="SpeedTest"></a>
<div class="frame_box">

<%	if action="SpeedTest" then%>
	<div id="txt_speed">网速测试中，请稍候...</div>
<%	end if%>	
	<div class="item_content" id='submenu3'>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
			<tr><th colspan="3">&nbsp服务器连接速度</th></tr>
        <tr align=center> 
          <td class=TableRow width="80">接入设备</td>
          <td class=TableRow width="405">连接速度(理想值)</td>
          <td class=TableRow width="115">下载速度(理想值)</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>56k Modem</td>
          <td class=TableRow><img src="" alt="" class="PicBar" width="1%"> 56 Kbps</td><td class=TableRow>7.0 k/s</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>2M ADSL</td>
          <td class=TableRow><img src="" alt="" class="PicBar" width="10%"> 2000 Kbps</td><td class=TableRow>250.0 k/s</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>5M FTTP</td>
          <td class=TableRow><img src="" alt="" class="PicBar" width="180"> 5000 Kbps</td>
          <td class=TableRow>625.0 k/s</td>
        </tr>
        <tr class=tr align=center> 
          <td class=TableRow>当前连接</td>
          <td class=TableRow>
          <%
	if action="SpeedTest" then
		dim i
		With Response
		.Write("<script language=""JavaScript"" type=""text/javascript"">var tSpeedStart=new Date();</script>")	
		.Write("<!--") & chr(13) & chr(10)
		for i=1 to 1000
		.Write("ITlearner-AspCheck-v1.3#############################################################################") & chr(13) & chr(10)
		next
		.Write("-->") & chr(13) & chr(10)
		.Write("<script language=""JavaScript"" type=""text/javascript"">var tSpeedEnd=new Date();</script>") & chr(13) & chr(10)		
		.Write("<script language=""JavaScript"" type=""text/javascript"">")
		.Write("var iSpeedTime=0;iSpeedTime=(tSpeedEnd - tSpeedStart) / 1000;")
		.Write("if(iSpeedTime>0) iKbps=Math.round(Math.round(100 * 8 / iSpeedTime * 10.5) / 10); else iKbps=10000 ;")
		.Write("var iShowPer=Math.round(iKbps / 100);")		
		.Write("if(iShowPer<1) iShowPer=1;  else if(iShowPer>82) iShowPer=82;")
		.Write("</script>") & chr(13) & chr(10)		
		.Write("<script language=""JavaScript"" type=""text/javascript"">") 
		.Write("document.write('<img class=""PicBar"" width=""' + iShowPer + '%""> ' + iKbps + ' Kbps');")
		.Write("</script>") & chr(13) & chr(10)
		.Write("</td><td class=TableRow><a href=""?action=SpeedTest"" title=""测试连接速度""><u>")
		.Write("<script language=""JavaScript"" type=""text/javascript"">")
		.Write("document.write(Math.round(iKbps/8*10)/10+ ' k/s');")		
		.Write("</script>") & chr(13) & chr(10)				
		.Write("</u></a>")
		.Write("<script language=""JavaScript"" type=""text/javascript"">")
		.Write("txt_speed.innerHTML=""网速测试完毕!"";")	
		.Write("txt_speed.style.display=""none"";")				
		.Write("</script>") & chr(13) & chr(10)		
		End With
	else
		Response.Write "</td><td class=TableRow><a href=""?action=SpeedTest#SpeedTest"" title=""测试连接速度""><u>开始测试</u></a>"
	end if
%>
          </td>
        </tr>
      </table>
	</div>
</div>
<br>
<%End Sub%>
<%Sub SystemCheck()%>
<div class="frame_box">
	<div class="item_content">
 <table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
             <tr class=td> 
			
			<td class=TableRow colspan="2">&nbsp系统用户(组)和进程检测</td>
    </tr>
            <tr class=tr align=center> 
			
			<td class=TableRow colspan="2">&nbsp如果下面列出了系统用户(组)和进程，则说明系统可能存在安全隐患。</td>
    </tr>
    <tr bgcolor="#EFEFEF">
      <td class=TableRow width="80" align="center">类 型</td><td class=TableRow width="400">名称及详情</td>
    </tr>
<%	dim obj
  	on error resume next
    for each obj in getObject("WinNT://.")
%>
    <tr bgcolor="#FFFFFF">
      <td class=TableRow align="center"><!--<%=obj.path%>-->
<%  if err=438 then Response.Write "系统用户(组)" : else Response.Write "系统进程"%>
      </td>
      <td class=TableRow><%Response.Write obj.Name
	  if not error then Response.Write " (" & obj.displayname & ")<br>" & obj.path%>
      </td>
    </tr>
<%	err.clear		
		next 
%>
  </table>
  
  </div>
</div>
<%
	Response.End
End Sub%>
</body>
</html>
