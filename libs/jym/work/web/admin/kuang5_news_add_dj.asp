<%
if Request.Cookies("admindj")="1" then
%>
&nbsp;<!--webbot bot="Validation" s-display-name="栏目分类" b-value-required="TRUE" b-disallow-first-item="TRUE" --><select size="1" name="lm">
					<option>请选择</option>
					  <%					  
					  sql = "select * from lm where lm<>'' order by id asc"
					  Set rs = Server.CreateObject("ADODB.RecordSet")
					  rs.Open sql,conn,1,1
					  while not rs.eof
					       response.write "<optgroup label='"&rs("lm")&"'>"
							sql2 = "select * from lm where lmid='"&rs("id")&"' order by id asc"
							Set rs2 = Server.CreateObject("ADODB.RecordSet")
							rs2.Open sql2,conn,1,1
							while not rs2.eof
							%>
							   <option value='<%=rs("id")%>|<%=rs2("id")%>' <% if int(lmid)=rs2("id") then response.write " selected" %>>├(编号:<%=rs2("id")%>)<%=rs2("lm2")%></option>
							<%
							rs2.movenext
							wend
					  rs.movenext
					  wend 
					  rs.close
					  set rs=nothing
					 
					%>
					
					</select>
<%else%>
<!--webbot bot="Validation" s-display-name="栏目分类" b-value-required="TRUE" b-disallow-first-item="TRUE" --><select size="1" name="lm">
					<option>请选择</option>
					  <%
					  sql3 = "select * from admin where user='"&session("kuang5__user")&"' order by id desc"
					  Set rs3 = Server.CreateObject("ADODB.RecordSet")
					  rs3.Open sql3,conn,1,1
					   lmid=rs3("lmid")
					   nr=split(lmid,",")
					   For i=0 to ubound(nr)
					        aaa=nr(i)
							sql2 = "select * from lm where id="&aaa
							Set rs2 = Server.CreateObject("ADODB.RecordSet")
							rs2.Open sql2,conn,1,1
							while not rs2.eof
							%>
							   <option value='<%=rs2("lmid")%>|<%=rs2("id")%>' <% if int(lmid)=rs2("id") then response.write " selected" %>>├(编号:<%=rs2("id")%>)<%=rs2("lm2")%></option>
							<%
							rs2.movenext
							wend
						next
					  rs2.close
					  set rs2=nothing
					 
					%>
					
					</select>
<%end if%>