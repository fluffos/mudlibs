<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<TITLE>pkuxkx anti robot page</TITLE>
<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=iso-8859-1">
</head>
<body>
<?PHP
require_once('b2evo_captcha.config.php');
require_once('b2evo_captcha.class.php');

if(strwidth($_GET["filename"]) > 0)
{
	if(strstr($_SERVER["HTTP_USER_AGENT"],"LuaSocket") == FALSE) 
        {
		$filename = "/usr/local/mud/xkx/pkuxkx/web/antirobot/".$_GET["filename"];
		if(is_file($filename))
		{
			//Initialize the captcha object with our configuration options
			$captcha =& new b2evo_captcha($CAPTCHA_CONFIG);

			$imgLoc = $captcha->get_b2evo_captcha();
			
			echo '<img src="'.$imgLoc.'" alt="This is a captcha-picture. It is used to prevent robots." title=""><br>'."\n";
			echo "<H3>If you can not read the image, please refresh the page to genenrate new.<H3><br>";

		}
	}
}
//show an input controller for user input filename
echo "<form action=\"robot.php\" method=\"GET\">\n";
echo "<input  name=\"filename\" value=\"\" />";
echo "<input type=\"submit\" value=\"check\" />";

echo "</form>\n";
?>
</body>
</html>
