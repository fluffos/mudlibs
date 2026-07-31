<%@LANGUAGE="VBSCRIPT"%>
<%
	option explicit
	dim startime
	dim conn
	dim connstr
	dim db
	startime=timer()
	'更改数据库名字
	db="data/dvBBS5.MDB"
	Set conn = Server.CreateObject("ADODB.Connection")
    connstr="driver={Microsoft Access Driver (*.mdb)};dbq=" & Server.MapPath(db)
	conn.Open connstr

function CloseDatabase

	Conn.close
	Set conn = Nothing

End Function
%>