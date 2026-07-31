
<html>
<head>
<title>狂舞网 - 管理后台</title>
<meta http-equiv=Content-Type content=text/html; charset=gb2312>
<link type=text/css href="images/style_frame.css" rel=stylesheet>
<script language=javascript>

function get_today()
{
  var now = new Date();
  var yys=now.getYear()
  var yy=(yys < 1000) ? yys + 1900 : yys;
  var dd = now.getDate() , mt = now.getMonth() + 1 ,weekVal = now.getDay();
  if (weekVal==0)
    msg1="星期日";
  else if (weekVal==1)
    msg1="星期一";
  else if (weekVal==2)
    msg1="星期二";
  else if (weekVal==3)
    msg1="星期三";
  else if (weekVal==4)
    msg1="星期四";
  else if (weekVal==5)
    msg1="星期五";
  else if (weekVal==6)
    msg1="星期六";
  return "今天是 "+yy+"-"+mt+"-"+dd+" "+msg1;
}
</script>
</head>
<body leftmargin=0 topmargin=0 marginheight="0" marginwidth="0" scroll=no style="border-top-width: 0px; border-left-width: 0px; border-bottom-width: 0px; border-right-width: 0px;"> 
<table border=0 cellpadding=0 cellspacing=0 width="100%" height="24">
<tr><td height=22 align=center>
  <table border=0 width="100%">
  <tr align=center>
  <td width=120>&nbsp;</td>
  <td width=10></td>
  <td width=60>系统公告：</td>
  <td width="*">
    <table border=0 width="100%">
    <tr>
    <td><script TYPE="text/javascript" language="javascript" src="http://www.kuang5.com/kuang5cms/adminnewsd.asp"></script></td>
    <td align=right><script language=javascript>document.write(get_today());</script></td>
    </tr>
    </table>
  </td>
  </tr>
  </table>
</td></tr>
</table>

</body>
</html>
<!-- Processed in 0.016 s, 0 queries -->
