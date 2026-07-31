<!--#include file = kuang5_chk.asp -->
<!--#include file = language.asp -->
<!--#include file = kuang5_conn.asp -->
<%
'=================================
'   狂舞游戏网站管理系统
'   www.kuang5.com
'  copyright(c)2007-2009 狂舞网络
'=================================
%>
<%


Select Case request("action")
    Case "kuang5_top"
	    Call kuang5_top()
	Case "SaveCommSetting"
		Call SaveCommSetting()
End Select

On Error Resume Next
Call LZ8.ChkCommReg
If Err Then
	Err.Clear
End If
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>狂舞网--后台管理</title>
<link type=text/css href="images/style_frame.css" rel=stylesheet>
<link rel="icon" href="Images/logo.ico" type="image/x-icon" />
<link rel="shortcut icon" href="Images/logo.ico" type="image/x-icon" />
<script language="JavaScript">

 var msg  = "欢迎使用狂舞游戏网站系统    " ;

var interval = 120

var spacelen = 120;

var space10=" ";

var seq=0;

function Scroll() {

len = msg.length;

window.status = msg.substring(0, seq+1);

seq++;

if ( seq >= len ) { 

seq = 0; 

window.status = '';

window.setTimeout("Scroll();", interval );

}

else

window.setTimeout("Scroll();", interval );

} 

Scroll();

</script>
<script language='JavaScript' type='text/JavaScript'>
function preloadImg(src) {
  var img=new Image();
  img.src=src
}
preloadImg('Images/kuang5_top_open.gif');

var displayBar=true;
function switchBar(obj) {
  if (displayBar) {
    parent.frame.cols='0,*';
    displayBar=false;
    obj.src='Images/kuang5_top_open.gif';
    obj.title='打开左边管理导航菜单';
  } else {
    parent.frame.cols='150,*';
    displayBar=true;
    obj.src='Images/kuang5_top_close.gif';
    obj.title='关闭左边管理导航菜单';
  }
}
</script>
</head>
<frameset rows="45,*,24" border=0 frameborder="YES" name="top_frame">
  <frame src="kuang5_index.asp?action=kuang5_top" noresize frameborder="NO" name="ads" id="ads" scrolling="NO"  marginwidth="0" marginheight="0">
<frameset rows="*" cols="166,*" framespacing="0" frameborder="yes" border="0" id="frame">
  <frame src="menu.asp" name="leftFrame" frameborder="no" scrolling="yes" noresize marginwidth="1" bordercolor="#999999">
  <frame src="kuang5_main.asp" name="main" frameborder="no" scrolling="yes" marginwidth="1" bordercolor="#999999" id="main">
</frameset><frame src="kuang5_d.asp" noresize frameborder="NO" name="ads" id="ads" scrolling="NO"  marginwidth="0" marginheight="0"></frameset>
<noframes></noframes>
</html>
<%
Sub kuang5_top()
%>

<link type=text/css href="images/style.css" rel=stylesheet>
<div id="SysShowMessage" style="position:absolute; left: 300px; top:2px; width:150px; height:26px; z-index:1; background-color:FFFBE7; font-size:14px; text-align:center; line-height:20px; padding-left:5px; padding-top:5px; display:none;">正在保存内容,请稍候...</div>
<table border=0 cellpadding=0 cellspacing=0 width="100%" height="100%">
<tr><td align=center height=44 background="images/top_bg.gif">
  <table border=0 cellpadding=0 cellspacing=0 width="100%" height="100%">
  <tr>
  <td width=6><img src="images/top_left.gif" border=0 width=6 height=44></td>
  <td width="*">
    <table border=0 width='100%'>
    <tr>
    <td width=20></td>
    <td>
      <table border=0>
      <tr>
	  <%
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.Open "select * from [config]",conn,1,1
%>
      <td><a class=h_t href="/" target=_blank><%=rs("webname")%></a></td>
      <td width=80></td>
      <td>→ 欢迎进入管理平台</td>
      </tr>
      </table>
    </td>
    <td align=right>
      <table border=0>
      <tr>
      <td></td>
      <td><img border=0 src="images/arrow_top.gif" align=absmiddle><a href="kuang5_main.asp" target=main>管理后台</a></td>
      <td width=10></td>
      <td><img border=0 src="images/arrow_top.gif" align=absmiddle><a href="http://www.Kuang5.com/" target=_blank>帮助中心</a></td>
      <td width=10></td>
      <td><img border=0 src="images/arrow_top.gif" align=absmiddle><a href="javascript:;" target=main onClick="window.location.reload()">刷新页面</a></td>
      <td width=10></td>
      <td><img border=0 src="images/arrow_top.gif" align=absmiddle><a href="kuang5_exit.asp" target="_top">退出管理</a></td>
      <td width=5></td>
      </tr>
      </table>
    </td>
    </tr>
    </table>
  </td>
  <td width=200><a href="http://www.kuang5.com/" target=_blank title="Kuang5 CMS 2.2 - A Best Game Content Management System!"><img src="images/top_cms.gif" border=0></a></td>
  </tr>
  </table>
</td></tr>
</table>
<%
End Sub
rs.close
set rs=nothing
conn.close
set conn=nothing
%>
