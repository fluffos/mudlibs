<%
sss=LCase(request.servervariables("QUERY_STRING"))
   if instr(sss,"select")<>0 or instr(sss,"inster")<>0 or instr(sss,"delete")<>0 or instr(sss,"(")<>0 or instr(sss,"'or")<>0 then
     response.write "<BR><BR><center>你的网址不合法"
     response.end
   end if

kuang5mdb=mdb&"data/#Kuang5_data.asp"

set conn=server.CreateObject("adodb.connection")
DBPath = Server.MapPath(kuang5mdb)
conn.open "provider=microsoft.jet.oledb.4.0; data source="&DBpath

'ON ERROR RESUME NEXT

userip = Request.ServerVariables("HTTP_X_FORWARDED_FOR")
If userip = "" Then userip = Request.ServerVariables("REMOTE_ADDR")

set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select zuziip from [config] where zuziip like '%"&zuziip&"%'",conn,1,1
if rs.recordcount<>0 then
	zuziip=rs("zuziip")&chr(13)
	zuziip=replace(zuziip," ","")
	zuziip=replace(zuziip,chr(10),"")
	'zuziip=replace(zuziip,".","")
	'userip2=replace(userip,".","")
	zzip=split(zuziip,chr(13))
	'Response.Write "ubound(zzip):"&ubound(zzip)&"<BR>"
	'Response.Write "zzip(0):"&zzip(0)&"<BR>"
	'Response.Write "zzip(1):"&trim(zzip(1))&"<BR>"
	for i=0 to ubound(zzip) 
		if userip=trim(zzip(i)) then
			er=1
			'Response.Write userip&"　"&zzip(i)&"<BR>"
		end if
	next

	if er=1 then
		Response.Write "<BR><BR><BR><BR><Center><font style='font-size:10.5pt'>你所在IP被系统阻止！("&userip&")</font><BR><BR></center>"
		conn.close:set conn=nothing
		Response.end
	end if
end if

%>


