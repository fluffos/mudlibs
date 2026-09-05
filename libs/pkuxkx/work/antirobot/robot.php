<?php	    
error_reporting(E_ALL^E_NOTICE^E_WARNING);
require_once('b2evo_captcha.config.php');
require_once('b2evo_captcha.class.php');
$max_refresh = 25;
    //anti robot page
	if(isset($_GET["filename"]))
	{
		$filename = $_GET["filename"];
		$mudfilename = "/usr/local/mud/xkx/pkuxkx/web/antirobot/".$_GET["filename"];
		$mudfilename = str_replace(".jpg","",$mudfilename);
		if(is_file($mudfilename))
		{
                        $captcha = new b2evo_captcha($CAPTCHA_CONFIG);
                        $imgLoc = $captcha->get_b2evo_captcha();
			if(!isset($_GET["zmud"]))
			{
				echo "<html>";
				echo '<img src="'.$imgLoc.'" alt="This is a captcha-picture. It is used to prevent robots." title=""><br>'."\n";
				echo "<H3>If you can not read the image, please refresh the page to genenrate new.<H3><br>";
				echo "</html>";
			}
			else
			{
				$filename = $_GET["filename"];
				header("Content-type: image/jpg");
				header('Content-Disposition: attachment; filename="'.$filename.'"');
				readfile($imgLoc);
			}
		}		
	}
    if(isset($_GET["gettest"]))
	{
        echo readfile("/usr/local/mud/xkx/pkuxkx/web/antirobot/".$_GET["gettest"]);
    }
?>