					&nbsp;<!--webbot bot="Validation" s-display-name="栏目分类" b-value-required="TRUE" b-disallow-first-item="TRUE" --><select size="1" name="lm">
					<option>请选择</option>
<%
			       lmid=rs("lmid")
			       if len(lmid)>1 then
			         iii=replace(lmid,"|",",")
			         iii=replace(lmid,",","|")
			             if len(iii)=1 then bb=iii
				         aa=split(iii,"|")			         
				         abcd=len(iii)
				         abcd=abcd/2-2
				         abc=int(abcd)
				         if abcd>abc then abcd=abc+1
				         abc=int(abcd)
				         abcd=abc
				         'response.write abcd
				         'response.end
				         i=0
				          for each ai in split(iii,"|")
				              if aa(i)<>"" then
				               bb=aa(i)
				               i=i+1
				               sql3 = "select * from lm where id="&bb
				               Set rs3 = Server.CreateObject("ADODB.RecordSet")
				               rs3.Open sql3,conn,1,1
				               if rs3.recordcount<>0 then
				                  response.write rs3("lm")&","
				               else
				                  response.write "<font color=blue>[无栏目编号为:"&bb&"]</font>"
				               end if
				               rs3.close
				               set rs3=nothing
				              end if
				          next
			       elseif len(lmid)=1 then
			          sql2 = "select * from lm where id="&lmid
			          Set rs2 = Server.CreateObject("ADODB.RecordSet")
			          rs2.Open sql2,conn,1,1
			          if rs2.recordcount<>0 then
 			             response.write rs2("lm")
 			          else
 			             response.write "找不到栏目，编号:"&lmid
 			          end if
 			          rs2.close
 			          set rs2=nothing
			       else
			         response.write "<font color=blue>无栏目</font>"
			       end if
%>
					
					</select>