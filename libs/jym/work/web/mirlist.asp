<!--#include file = kuang5_conn.asp -->
<table cellSpacing=1 cellPadding=5 width=100% bgColor=#4C4B49 border=0>
<%

Function glhtmlgg(name)
  name=replace(name,"&nbsp;","")
  name=replace(name,"""","'")
  name=replace(name,chr(10),"")
  name=replace(name,chr(13),"<br>")
  glhtmlgg=name
  set reg=nothing
End Function




  sql="select * from [gamelist]"

if id<>"" then sql=sql&" where id="&clng(id)
sql=sql&" order by id desc"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open sql,conn,1,1
while not rs.eof
  name=rs("name")
  ip=glhtmlgg(rs("ip"))
  addtime=rs("addtime")
  ap=rs("ap")
  dlq=rs("dlq")
  color=rs("color")
 if ap="正常" then
   picap="images/1.gif"
  elseif ap="繁忙" then
   picap="images/2.gif"
 else
   picap="images/3.gif"
end if
%>
	<tr onMouseOver="javascript:this.bgColor='#252525'" onMouseOut="javascript:this.bgColor='#424242'" bgColor=#424242>
		<td width=165 style="font-size: 12px;color:<%=color%>"><b><%=name%></b></td>
		<TD width=170 style="font-size: 12px;color:<%=color%>"><A style="color:<%=color%>" href="<%=dlq%>" target=_blank><b><%=ip%></b></A></TD>
		<TD width=181 style="font-size: 12px;color:<%=color%>"><%=addtime%></TD>
		<TD width="161" align="center" style="font-size: 12px;color:<%=color%>"><%=ap%></TD></tr>

<%
	
	
rs.movenext
wend

rs.close
set rs=nothing
%>

</table>