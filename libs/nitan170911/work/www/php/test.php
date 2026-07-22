<?php
	include("mysql.php");


   $img_width=400;
   $img_height=40;

   if(isset($_GET['key'])) {
       $str = mysql_check($_GET['key']); 
   } else {
       $str = "no data!";
   }
   $new_number=imageCreate($img_width,$img_height);//....
   ImageColorAllocate($new_number,255,255,255);  //........

   for($i=0;$i<strlen($str);$i++)
   {
       $font=mt_rand(3,5);
       $x=mt_rand(1,8) + $img_width*$i/8;
       $y=mt_rand(1,$img_height/8);
       $color=imageColorAllocate($new_number,mt_rand(0,100),mt_rand(0,150),mt_rand(0,200));//......
       imageString($new_number,$font,$x,$y,$str[$i],$color);//....
   }
   Header("Content-type: image/png");
   ImagePng($new_number);
   ImageDestroy($new_number);
?>
