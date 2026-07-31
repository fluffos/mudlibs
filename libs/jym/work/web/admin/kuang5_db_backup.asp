<%
if Request.Cookies("admindj")<>"1" then
   Response.Write "<BR><BR><BR><BR><center>权限不足，你没有此功能的管理权限"
   Response.end
end if
%>
<!--#include file = kuang5_chk.asp -->
<!--#include file = titleb.asp -->
<LINK href="admin_style.css" type=text/css rel=StyleSheet>
<%
dim action
dim kuang5_flag

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


	action=trim(request("action"))

dim dbpath,bkfolder,bkdbname,fso,fso1
Dim uploadpath

	'备份数据

select case action
case "BackupData"		'备份数据
		if request("act")="Backup" then
			call updata()
		else
			call BackupData()
		end if

case "RestoreData"		'恢复数据
	dim backpath
		if request("act")="Restore" then
			Dbpath=request.form("Dbpath")
			backpath=request.form("backpath")
			if dbpath="" then
			response.write "请输入您要恢复成的数据库全名"	
			else
			Dbpath=server.mappath(Dbpath)
			end if
			backpath=server.mappath(backpath)
		
			Set Fso=server.createobject("scripting.filesystemobject")
			if fso.fileexists(dbpath) then  					
			fso.copyfile Dbpath,Backpath
			response.write "<br>"
			response.write "<br>"
			response.write "<br>"
			response.write "<center>成功恢复数据！"
			response.write "</center>"			
			else
			response.write "备份目录下并无您的备份文件！"	
			end if
		else
		
			call RestoreData()
		end if
end select


'====================备份数据库=========================
sub BackupData()
If IsSqlDataBase = 1 Then
	SQLUserReadme()
	Exit Sub
End If
%>
<body bgcolor="#EFEFDE">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr class="tr"><th align="left" colspan="3">&nbsp;数据库管理</th></tr>
<tr class=tr><td class=tablerow width="16%">

<img border=0 src="images/s.gif" align=absmiddle><a href="kuang5_db_backup.asp?action=BackupData" class=h_p_bar>数据库备份</a>&nbsp;</td>
  <td class=tablerow width="14%"><img border=0 src="images/s.gif" align=absmiddle><a href="kuang5_db_backup.asp?action=RestoreData" class=h_p_bar>数据库恢复</a>&nbsp;</td>
  <td class=tablerow width="70%"><img border=0 src="images/s.gif" align=absmiddle><a href="kuang5_db_ys.asp" class=h_p_bar>数据库压缩</a>&nbsp;</td>
</tr>
</table>
<table border=0><tr class="tr"><td height=3></td></tr></table>
	<div align="center">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
  				<tr class="th">
  				  <th colspan="3" class="td">
				    <div align="left">备份数据( 需要FSO支持，FSO相关帮助请看微软网站 )  					</div></th>
				</tr>
  				<form method="post" action="kuang5_db_backup.asp?action=BackupData&act=Backup">	
  				<tr class="tr">
  				  <td class=tablerow>&nbsp;当前数据库路径(相对路径)：</td>
  					<td class=tablerow>
  						<input type=text class="txt" size=45 name=DBpath value="../data/#Kuang5_data.asp"></td>
  				    <td class=tablerow>&nbsp;</td>
  				</tr>	
  				<tr class="tr">
  				  <td class=tablerow>&nbsp;备份数据库目录(相对路径)：</td>
  					<td class=tablerow>
  						<input type=text class="txt" size=45 name=bkfolder value=Databackup></td>
  				    <td class=tablerow><font color="#FF0000">如目录不存在，程序将自动创建</font></td>
  				</tr>	
  				<tr class="tr">
  				  <td class=tablerow>&nbsp;备份数据库名称(填写名称)：</td>
  					<td class=tablerow>
  						<input type=text class="txt" size=45 name=bkDBname value=#Kuang5_data.asp></td>
  				    <td class=tablerow><font color="#FF0000">如备份目录有该文件，将覆盖，如没有，将自动创建</font></td>
  				</tr>	
  				<tr class="trb">
  				  <td class=tablerow>&nbsp;</td>
  					<td class=tablerow>
					    <input type=submit class="btn" value="备份数据"></td>
  				    <td class=tablerow>&nbsp;</td>
  				</tr>	
  				<tr class="tr">
  				  <td colspan="3" class=tablerow>&nbsp;&nbsp;<font color="#FF0000">在上面填写本程序的数据库路径全名，本程序的默认数据库文件为database/#kuang5cms.asp，<B><br>
				  请一定不能用默认名称命名备份数据库</B>您可以用这个功能来备份您的法规数据，以保证您的数据安全！<br>
				  &nbsp;注意：所有路径都是相对与程序空间根目录的相对路径				</font>
				  </font>  					</td>
				  </tr>	
  				</form>
  			</table>
</div>
<%
end sub

sub updata()
		Dbpath=request.form("Dbpath")
		Dbpath=server.mappath(Dbpath)
		bkfolder=request.form("bkfolder")
		bkdbname=request.form("bkdbname")
		Set Fso=server.createobject("scripting.filesystemobject")
		if fso.fileexists(dbpath) then
			If CheckDir(bkfolder) = True Then
			fso.copyfile dbpath,bkfolder& "\"& bkdbname
			else
			MakeNewsDir bkfolder
			fso.copyfile dbpath,bkfolder& "\"& bkdbname
			end if
			response.write "<br>"
			response.write "<br>"
			response.write "<br>"						
			response.write "<center>备份数据库成功，您备份的数据库路径为　服务器空间的：" &bkfolder& "\"& bkdbname
			response.write "</center>"
		Else
			response.write "找不到您所需要备份的文件。"
		End if
end sub
'====================恢复数据库=========================
sub RestoreData()

%>
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr class="tr"><th align="left" colspan="3">&nbsp;数据库管理</th></tr>
<tr class=tr><td class=tablerow width="16%">

<img border=0 src="images/s.gif" align=absmiddle><a href="kuang5_db_backup.asp?action=BackupData" class=h_p_bar>数据库备份</a>&nbsp;</td>
  <td class=tablerow width="14%"><img border=0 src="images/s.gif" align=absmiddle><a href="kuang5_db_backup.asp?action=RestoreData" class=h_p_bar>数据库恢复</a>&nbsp;</td>
  <td class=tablerow width="70%"><img border=0 src="images/s.gif" align=absmiddle><a href="kuang5_db_ys.asp" class=h_p_bar>数据库压缩</a>&nbsp;</td>
</tr>
</table>
<table border=0><tr class="tr"><td height=3></td></tr></table>
<div align="center">
<table width=98% align="center" border="0" cellspacing="1" cellpadding="2" class="tableBorder">
<tr class="tr">
  <th colspan="2" class="td">
	  <div align="left">恢复数据( 需要FSO支持，FSO相关帮助请看微软网站 )  					</div></th>
	</tr>
				<form method="post" action="kuang5_db_backup.asp?action=RestoreData&act=Restore">
  				<tr class="tr">
  				  <td width="22%" class=tablerow>&nbsp;备份数据库路径(相对)：</td>
  					<td width="78%" class=tablerow>
  						<input type=text class="txt" size=30 name=DBpath value="DataBackup\#Kuang5_data.asp">&nbsp;</td>
  				</tr>	
  				
  				<tr class="tr">
  				  <td class=tablerow>&nbsp;目标数据库路径(相对)：</td>
  					<td class=tablerow>
  						<input type=text class="txt" size=30 name=backpath value="../data/#Kuang5_data.asp"></td>
  				</tr>	
  				
  				<tr class="tr">
  				  <td colspan="2" class=tablerow>
					  <font color="#FF0000">
				  &nbsp;填写您当前使用的数据库路径，如不想覆盖当前文件，可自行命名（注意路径是否正确），然后修改kuang5_conn.asp<span lang="zh-cn">和member下的conn</span>.<span lang="zh-cn">asp</span>文件，如果目标文件名和当前使用数据库名一致的话，不需修改kuang5_conn.asp<span lang="zh-cn">和member下的conn</span>.<span lang="zh-cn">asp</span>文件</font></td>
				  </tr>	
  				<tr class="trb">
  				  <td class=tablerow>&nbsp;</td>
  					<td class=tablerow>
  						  <input type=submit class="btn" value="恢复数据"></td>
  				</tr>
  				
  				<tr class="tr">
  				  <td colspan="2" class=tablerow>
					  &nbsp;<font color="#FF0000">&nbsp;在上面填写本程序的数据库路径全名，本程序的默认备份数据库文件为DataBackup\#kuang5cms.asp，请按照您的备份文件自行修改。<br>
					  &nbsp;&nbsp;您可以用这个功能来备份您的法规数据，以保证您的数据安全！<br>
					  &nbsp;&nbsp;注意：所有路径都是相对与程序空间根目录的相对路径</font>
				    </font>  					</td>
				  </tr>	
  				</form>
  			</table>
</div>

<%
end sub

'------------------检查某一目录是否存在-------------------
Function CheckDir(FolderPath)
	folderpath=Server.MapPath(".")&"\"&folderpath
    Set fso1 = CreateObject("Scripting.FileSystemObject")
    If fso1.FolderExists(FolderPath) then
       '存在
       CheckDir = True
    Else
       '不存在
       CheckDir = False
    End if
    Set fso1 = nothing
End Function
'-------------根据指定名称生成目录-----------------------
Function MakeNewsDir(foldername)
	dim f
    Set fso1 = CreateObject("Scripting.FileSystemObject")
        Set f = fso1.CreateFolder(foldername)
        MakeNewsDir = True
    Set fso1 = nothing
End Function
%>