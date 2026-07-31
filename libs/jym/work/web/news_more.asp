<!--#include file="kuang5_h.asp"-->
<!--#include file="head.asp"-->
<!--#include file = news_list.asp -->
<!--#include file = titleb.asp -->
<%
lm2 =trim(request("lm2"))
lm=trim(request("lm"))
if lm2="" then lm2=lm
if lm="" then lm=lm2
if lm2="" then lm2=0

if (not isNumeric(lm)) then
	lm=0
end if


  sql2 = "select * from lm where id="&lm2
  Set rs2 = Server.CreateObject("ADODB.RecordSet")
  rs2.Open sql2,conn,1,1
   if rs2.recordcount=0 then
	  sql2 = "select * from lm order by id asc"
	  Set rs2 = Server.CreateObject("ADODB.RecordSet")
	  rs2.Open sql2,conn,1,1
   end if
   if rs2.recordcount <> 0 then
     mb=trim(rs2("mb"))
     lmm=rs2("lm")&rs2("lm2")&rs2("lm3")
     'Response.Write lmm
     if lm2="0" then lmm="所有栏目"
     
     if mb<>"" then

     sql3 = "select * from xymb where id="&clng(mb)
     Set rs3 = Server.CreateObject("ADODB.RecordSet")
     rs3.Open sql3,conn,1,1
     if rs3.recordcount<>0 then
	     listm=rs3("listm")
	     listshu=rs3("list")
	     tb=rs3("tb")
	     lmnameid=rs3("lmname")
	     newstime=rs3("newstime")
	     newshit=rs3("newshit")
	     openwindow=rs3("openwindow")
	     icon=rs3("icon")
         listm=replace(listm,"$$kefu$$",kefu)	
	     listm=replace(listm,"$$Columns$$",lmm)
	     listm=replace(listm,"$$Path$$",lmaa())
	     listm=replace(listm,"$$LMID$$",trim(request("lm2")))
		 else
		    Response.Write "模版设置不正确或已经被删除!"
		 end if     
	     if instr(listm,"$$List$$")<>0 then
		     nr=split(listm,"$$List$$")
		     Response.Write lmid
		     response.write nr(0)
		     
		     Response.Write newslist(listshu,tb,lmnameid,openwindow,icon)
		     Response.Write nr(1)
		 else
			 Response.Write "模版代码不正确，没有找到“$$List$$”，不知道应该显示在哪里？"
		 end if
		 rs3.close:set rs3=nothing
	  else
	  	Response.Write "模版代码不正确或已经被删除!"
	  end if
	  
   else
     Response.Write "模版没有找到或者没有设置"
   end if
%>
<!--#include file="foot.asp"-->
<%
conn.close:set conn=nothing
%>