<!--#include file = kuang5_conn.asp -->

<!--
function FP_jumpMenu(el,frm,sel) {//v1.0
 var href=el.options[el.selectedIndex].value; if(sel) el.selectedIndex=0;
 if('_new'==frm) open(href); else eval(frm+".location='"+href+"'");
}
// -->


<%
linktype=trim(request("link"))
n=trim(request("n"))
w=trim(Request("w"))
h=trim(Request("h"))
if n="" then n=8
if w="" then w=5
if h="" then h=5



if linktype="1" then
	sql = "select * from link order by ontop desc , upd desc , id desc"
	Set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open sql,conn,1,1
	%>
	  document.write("<SELECT onchange=\"FP_jumpMenu(this,'_new',false)\" id=id1 name=D1>");
	  document.write("<option>友情链接</option>");
	<%
	while not rs.eof
		url=rs("url")
		linkname=rs("linkname")
		%>
		  
		  document.write("<option value=<%=url%>><%=linkname%></option>");
		<%
	rs.movenext
	wend
		%>
		document.write("</select>");

<%
elseif linktype="2" and w<>"" and n<>"" then
	if n<>"0" then 
		ttt="top "&n
	end if
	sql = "select "&ttt&" * from link  where logo='' order by ontop desc , upd desc , id desc"
	Set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open sql,conn,1,1
	if rs.recordcount<>0 then
	    %>
	    document.write("<table border=0 cellpadding=0 cellspacing=0 width=100% id=table1>");
	    <% 
	    for k=1 to rs.recordcount
	    %>
	    document.write("<tr>");
	    <%
		for i=1 to h
		url=rs("url")
		linkname=rs("linkname")
		%>
			document.write("<td align=center><a href=<%=url%> title='<%=linkname%>' target=_blank><%=linkname%></a></td>");
		<%
		rs.movenext
		if rs.eof then exit for
		next
		%>
		document.write("</tr>");
		<%
		if rs.eof then exit for
		next
		%>
		document.write("</table>");
		<%
	end if
	rs.close:set rs=nothing
	
	
elseif linktype="3" then

	if n<>"0" then 
		ttt="top "&n
	end if
	
	sql = "select "&ttt&" * from link where logo='' order by ontop desc , upd desc , id desc"
	Set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open sql,conn,1,1
	if rs.recordcount<>0 then
	    %>
	    document.write("<table border=0 cellpadding=2 cellspacing=0 width=100% id=table1>");
	    <%
		for i=1 to n
		url=rs("url")
		linkname=rs("linkname")
		%>
		   document.write("<tr><td align=center><a href='<%=url%>' title='<%=linkname%>' target=_blank><%=linkname%></a></td></tr>");
		<%
		rs.movenext
		if rs.eof then exit for
		next
		%>
		document.write("</table>");
		<%
	end if
	rs.close:set rs=nothing

elseif linktype="4" then
	sql = "select * from link where logo<>'' order by ontop desc , upd desc , id desc"
	Set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open sql,conn,1,1
	if rs.recordcount<>0 then
	    %>
	    document.write("<table border=0 cellpadding=0 cellspacing=0 width=100% id=table1><tr>");
	    <%
		for i=1 to n
		url=rs("url")
		linkname=rs("linkname")
		logo=rs("logo")
		js=rs("js")
		%>
		   document.write("<td align=center><a href='<%=url%>' title='<%=js%>' target=_blank><img width=88 height=31 border=0 src='<%=logo%>'></a></td>");
		<%
		rs.movenext
		if rs.eof then exit for
		next
		%>
		document.write("</tr></table>");
		<%
	end if
	rs.close:set rs=nothing
	
elseif linktype="5" then
	sql = "select * from link where logo<>'' order by ontop desc , upd desc , id desc"
	Set rs = Server.CreateObject("ADODB.RecordSet")
	rs.Open sql,conn,1,1
	if rs.recordcount<>0 then
	    %>
	    document.write("<table border=0 cellpadding=2 cellspacing=0 width=100% id=table1>");
	    <%
		for i=1 to n
		url=rs("url")
		linkname=rs("linkname")
		logo=rs("logo")
		js=rs("js")
		%>
		   document.write("<tr><td align=center><a href='<%=url%>' title='<%=js%>' target=_blank><img width=88 height=31 border=0 src='<%=logo%>'><br><%=rs("linkname")%></a></td></tr>");
		<%
		rs.movenext
		if rs.eof then exit for
		next
		%>
		document.write("</table>");
		<%
	end if

elseif linktype="6" then
%>
	document.write("<div align=center><table border=1 cellpadding=2 width=725 id=table2 style='border-collapse: collapse' bordercolor='#C0C0C0'>");
				<%
				  sql = "select * from link where logo is null order by ontop desc , upd desc , id desc"
				  Set rs = Server.CreateObject("ADODB.RecordSet")
				  rs.Open sql,conn,1,1
				  
				  if rs.recordcount<>0 then
			  
				  for i=0 to rs.recordcount
				   url=rs("url")
				   linkname=rs("linkname")
				%>
					document.write("<tr>");
					document.write("<td align=center><a href=<%=url%> title='<%=linkname%>' target=_blank><%=linkname%></a></td>");
								<%
				 					rs.movenext
				 					if rs.eof then exit for
				 					url=rs("url")
				 					linkname=rs("linkname")			
								%>
					document.write("<td align=center><a href=<%=url%> title='<%=linkname%>' target=_blank><%=linkname%></a></td>");
								<%
				 					rs.movenext
				 					if rs.eof then exit for		
				 					url=rs("url")
				 					linkname=rs("linkname")		
								%>
					document.write("<td align=center><a href=<%=url%> title='<%=linkname%>' target=_blank><%=linkname%></a></td>");
								<%
				 					rs.movenext
				 					if rs.eof then exit for	
				 					url=rs("url")
				 					linkname=rs("linkname")			
								%>									
					document.write("<td  align=center><a href=<%=url%> title='<%=linkname%>' target=_blank><%=linkname%></a></td>");
								<%
				 					rs.movenext
				 					if rs.eof then exit for	
				 					url=rs("url")
				 					linkname=rs("linkname")			
								%>									
					document.write("<td align=center><a href=<%=url%> title='<%=linkname%>' target=_blank><%=linkname%></a></td>");
					document.write("</tr>");
							<%
							  rs.movenext
							  if rs.eof then exit for
							  next
							  
							  end if
							%>
					document.write("</table></div><BR>");
					document.write("<div align=center><table border=1 cellpadding=5 width=725 id=table3 style='border-collapse: collapse' bordercolor=#C0C0C0>");
							<%
							  sql = "select * from link where logo<>'' order by id desc"
							  Set rs = Server.CreateObject("ADODB.RecordSet")
							  rs.Open sql,conn,1,1
							  
							  if rs.recordcount<>0 then
							  
							  for i=1 to 5
							    url=rs("url")
							    linkname=rs("linkname")
							    logo=rs("logo")
							    js=rs("js")
							%>
						document.write("<tr><td align=center><a href=<%=url%> title='<%=js%>' target=_blank><img width=88 height=31 border=0 src=<%=logo%>></a></td>");
								<%
								  rs.movenext
								  if rs.eof then exit for
								    url=rs("url")
								    linkname=rs("linkname")
								    logo=rs("logo")
								    js=rs("js")
								%>
						document.write("<td align=center><a href=<%=url%> title='<%=js%>' target=_blank><img width=88 height=31 border=0 src=<%=logo%>></a></td>");
								<%
								  rs.movenext
								  if rs.eof then exit for
								    url=rs("url")
								    linkname=rs("linkname")
								    logo=rs("logo")
								    js=rs("js")
								%>
						document.write("<td align=center><a href=<%=url%> title='<%=js%>' target=_blank><img width=88 height=31 border=0 src=<%=logo%>><br><%=rs("linkname")%></a></td>");
								<%
								  rs.movenext
								  if rs.eof then exit for
								    url=rs("url")
								    linkname=rs("linkname")
								    logo=rs("logo")
								    js=rs("js")
								%>
						document.write("<td align=center><a href=<%=url%> title='<%=js%>' target=_blank><img width=88 height=31 border=0 src=<%=logo%>></a></td>");
								<%
								  rs.movenext
								  if rs.eof then exit for
								    url=rs("url")
								    linkname=rs("linkname")
								    logo=rs("logo")
								    js=rs("js")
								%>
						document.write("<td align=center><a href=<%=url%> title='<%=js%>' target=_blank><img width=88 height=31 border=0 src=<%=logo%>></a></td></tr>");
								
							<%
							  rs.movenext
							  if rs.eof then exit for 
							  next
							  
							  end if
							%>
						document.write("</table></div>");
<%
end if
conn.close:set conn=nothing
%>