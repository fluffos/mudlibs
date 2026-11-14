<?php
/* Script for generating deathlists
   by Hactar@silberland
   V1.4 
   ----
   wird aufgerufen von /mud/scripts/daily.sh
*/

//For Forest
/*
$sourcefolder = '/mud/mudlib/log/combat/';
$destinationfolder = '/mud/mudlib/d/unterwelt/hactar/deathshome/data/';
$npcdestinationfolder = '/mud/mudlib/d/unterwelt/hactar/deathshome/npcdata/';
$convertfile = '/mud/mudlib/d/unterwelt/hactar/deathshome/convert';
$toplistfolder = '/mud/mudlib/d/unterwelt/hactar/deathshome/toplist/';
*/

$sourcefolder = './combat/';
$destinationfolder = './data/';
$npcdestinationfolder = './npcdata/';
$convertfile = './convert';
$toplistfolder = './toplist/';


// --- You do not need to edit anything below this line ---

function enemize($thestring)
{
	global $convertarray;
	$foo = explode("/",$thestring);
	if ($convertarray[ucfirst($foo[sizeof($foo)-1])] != '')
		return $convertarray[ucfirst($foo[sizeof($foo)-1])];
	return ucfirst($foo[sizeof($foo)-1]);
}

function ortize($thestring)
{
	$foo = strpos($thestring,"d.");
	if ($foo === false)
		return ;
	$bar = strpos($thestring,".",$foo+2);
	if ($bar === false)
		$bar = strlen($thestring);
	return str_replace(")","",ucfirst(substr($thestring,$foo+2,$bar-$foo-2)));
}

function stufenize($thestring)
{
	$foo = strpos($thestring,"[");
	$bar = strpos($thestring,",");
	return substr($thestring,$foo+1,$bar-$foo-1);
}

function oldplayerize($thestring)
{
	$bar = strpos($thestring,"(");
	return substr($thestring,0,$bar);
}

function oldstufenize($thestring)
{
	$foo = strpos($thestring,"(");
	$bar = strpos($thestring,",");
	return substr($thestring,$foo+1,$bar-$foo-1);
}
function getmicrotime(){ 
   list($usec, $sec) = explode(" ",microtime()); 
   return ((float)$usec + (float)$sec); 
   } 


function loadconverter()
{
	global $convertfile;
	$templines = file($convertfile);
	for ($i = 0; $i < sizeof($templines);$i++)
	{
		$myline = explode(",",$templines[$i]);
		$convertarray[$myline[0]] = $myline[1];
	}
	return $convertarray;
}

function deldir($dir) {
   $dh=opendir($dir);
   while (false !== ($file =readdir($dh))) {
       if($file!="." && $file!="..") {
           $fullpath=$dir."/".$file;
           if(!is_dir($fullpath)) {
               unlink($fullpath);
           } else {
               deldir($fullpath);
           }
       }
   }

   closedir($dh);
   
   if(rmdir($dir)) {
       return true;
   } else {
       return false;
   }
} 

function createtoplist($name,$thearray)
{
	global $toplistfolder;
	$i = 0;
	while (list($key, $val) = each($thearray)) 
	{
		$hitme[0][$i] = $key;
		$hitme[1][$i] = $val[1];
		$i++;
	}
	array_multisort($hitme[1],SORT_DESC,$hitme[0]);
	$handle = fopen($toplistfolder . $name . ".txt", 'w');
	fwrite($handle, str_pad("Rang",5)  . str_pad("Name",30) . str_pad("Anzahl",6) . "\n");
	fwrite($handle,"----------------------------------------------------------------------------------\n");
	$total = min(500,sizeof($thearray));
	for ($i = 0; $i < $total ;$i++)
	{
		fwrite($handle, str_pad($i + 1,5)  . str_pad($hitme[0][$i],30) . str_pad($hitme[1][$i],6) . "\n");
	}
fclose($handle);

}


//Main script starts here
$time_start = getmicrotime(); 
$year = 1997;
$stage = 1;
echo date("Y-m-d H:i:s") . ": Death list generation script started.\n";
echo "  Source: $sourcefolder \n";
echo "  Destination: $destinationfolder \n";
echo "  Loading convert file... ";
$convertarray = loadconverter();
echo "(" . sizeof($convertarray) . " entries)\n";

echo "  Parsing KILLS files... ";
$testfilename = sprintf( "%sKILLS.%03d", $sourcefolder, $i = 1 );
$lines = '';
$myarray = array();
$mynpcarray = array();
while (file_exists($testfilename))
{
	$lines = file($testfilename);
	//$lines = array_unique($lines);
	$lines = array_merge(array_flip(array_flip($lines)));
	for ($j = 0; $j < sizeof($lines); $j++)
	{
        $theline = explode(" ", trim(str_replace("  "," ",$lines[$j])));
        if (strpos($theline[3],'(') === false)
        {
                $date = $theline[0] . " " . $theline[1];
                $player = $theline[3];
                $stufe = stufenize($theline[4]);
                $enemy = trim(enemize($theline[5]));
                $ort = ortize($theline[6]);
        } else
        {
                $date = $theline[1] . " " . $theline[0];
                $player = oldplayerize($theline[3]);
                $stufe = oldstufenize($theline[3]);
                $enemy = trim(enemize($theline[4]));
        }
        if (($stage == 0) && !(strpos($date,'Feb') === false))
                $stage = 1;
        if (($stage == 1) && !(strpos($date,'Jan') === false))
        {
                $stage = 0;
                $year++;
        }
		if (strlen($player) == 0)
			echo $testfilename . " " .$j . ";";
			
        $myarray[$player][0] = $myarray[$player][0] . "\n" . str_pad($date,8) . str_pad($year,7) . str_pad($stufe,7) . str_pad($enemy,20) . str_pad($ort,13);
		$myarray[$player][1] = $myarray[$player][1] + 1;
		$mynpcarray[$enemy][0] = $mynpcarray[$enemy][0] . "\n" . str_pad($date,8) . str_pad($year,7) . str_pad($stufe,7) . str_pad($player,20) . str_pad($ort,13);
		$mynpcarray[$enemy][1] = $mynpcarray[$enemy][1] + 1;
	}
        $testfilename = sprintf( "%sKILLS.%03d", $sourcefolder, ++$i );
}	
$lines = file($sourcefolder . "KILLS");
$lines = array_merge(array_flip(array_flip($lines)));
for ($i = 0; $i < sizeof($lines); $i++)
{
	$theline = explode(" ", trim(str_replace("  "," ",$lines[$i])));
	if (strpos($theline[3],'(') === false)
	{
		$date = $theline[0] . " " . $theline[1];
		$player = $theline[3];
		$stufe = stufenize($theline[4]);
		$enemy = trim(enemize($theline[5]));
		$ort = ortize($theline[6]);
	} else
	{
		$date = $theline[1] . " " . $theline[0];
		$player = oldplayerize($theline[3]);
		$stufe = oldstufenize($theline[3]);
		$enemy = trim(enemize($theline[4]));
	}	
	if (($stage == 0) && !(strpos($date,'Feb') === false))
		$stage = 1;
	if (($stage == 1) && !(strpos($date,'Jan') === false))
	{
		$stage = 0;
		$year++;
	}
        $myarray[$player][0] = $myarray[$player][0] . "\n" . str_pad($date,8) . str_pad($year,7) . str_pad($stufe,7) . str_pad($enemy,20) . str_pad($ort,13);
		$myarray[$player][1] = $myarray[$player][1] + 1;
		$mynpcarray[$enemy][0] = $mynpcarray[$enemy][0] . "\n" . str_pad($date,8) . str_pad($year,7) . str_pad($stufe,7) . str_pad($player,20) . str_pad($ort,13);
		$mynpcarray[$enemy][1] = $mynpcarray[$enemy][1] + 1;
}
$mysize = sizeof($myarray);
$mynpcsize = sizeof($mynpcarray);
echo "	($mysize players, $mynpcsize npcs)\n";
echo "  Deleting old player death files...";
deldir($destinationfolder);
echo " done.\n";
echo "  Deleting old npc death files...";
deldir($npcdestinationfolder);
echo " done.\n";
echo "  Creating player death files...";
mkdir($destinationfolder);
reset($myarray);
while (list($key, $val) = each($myarray)) 
{
	@mkdir($destinationfolder . $key[0]);	
$filename = $destinationfolder . $key[0] . "/" . $key . ".txt";
$val = "Datum          Stufe  Feind               Ort\n" .  "----------------------------------------------------------------" . $val[0];
   if (!$handle = fopen($filename, 'w')) {
         print "Cannot open file ($filename)";
         exit;
   }

   if (!fwrite($handle, $val)) {
       print "Cannot write to file ($filename)";
       exit;
   }
   
   fclose($handle);
}
echo " done.\n";

echo "  Creating npc death files...";
mkdir($npcdestinationfolder);
reset($mynpcarray);
while (list($key, $val) = each($mynpcarray)) 
{
	@mkdir($npcdestinationfolder . $key[0]);	
$filename = $npcdestinationfolder . $key[0] . "/" . $key . ".txt";
$val = "Datum          Stufe  Feind               Ort\n" .  "----------------------------------------------------------------" . $val[0];
   if (!$handle = fopen($filename, 'w')) {
         print "Cannot open file ($filename)";
         exit;
   }

   if (!fwrite($handle, $val)) {
       print "Cannot write to file ($filename)";
       exit;
   }
   
   fclose($handle);
}
echo " done.\n";
/* TOPLISTS */
deldir($toplistfolder);
mkdir($toplistfolder);
reset($myarray);
createtoplist('topdeath',$myarray);
createtoplist('topkiller',$mynpcarray);
$time_end = getmicrotime();
$time = $time_end - $time_start;
echo date("Y-m-d H:i:s") . ": completed in $time seconds.\n";
?>
