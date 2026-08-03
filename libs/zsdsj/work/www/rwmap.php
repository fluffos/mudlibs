<?php

$map = $_GET["map"];
$size = $_GET["size"];

if( !$size ) $size=10;
if( !$map )
{
	echo "輸入參數錯誤";
	exit();
}
function show_html()
{
	global $map;
	global $size;

?>
<html>
<meta http-equiv=refresh content=300; url=.>
<body bgcolor='#000000' text='#cccccc' link='#999999' vlink='#999999'>
<form method="GET">
MAP Size:
<select onchange="this.form.submit();" name='size'>
<?php
	for($i=2; $i<26; $i+=2)
		echo "<option ".  ($i==$size ? 'selected':''). ">$i</option>";
?>
</select>
<input type="hidden" name="map" value="<? echo $map; ?>">
</form>
<applet
  code     = 'rwmapappletviewer.MapApplet.class'
  width    = 860
  height   = 380
>
<param name = 'url' value = 'http://www.revivalworld.org/online/rw/map/<? echo $map; ?>'>
<param name = 'fontSize' value = '<? echo $size; ?>'>
</applet>
<br>
若無法正常顯示地圖，請安裝 <a href='http://www.java.com/zh_tw/download/windows_automatic.jsp'><u>Java Runtime Environment (JRE)</u></a>。<br>
Designed by <font color=999999><u>Youngman@Revival World</u><br>
</body>
</html>
<?php
	echo $content;
}

show_html();

?>   
