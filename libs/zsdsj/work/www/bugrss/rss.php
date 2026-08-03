<?php
    function processContent($data,$reply)
    {
        if(sizeof($reply))
	{
	    $data .= "\nresponse:<ul>";
	    for($i = 0 ;$i<sizeof($reply);$i++)
	    {
		$data .= "<li>".$reply[$i][0].":".$reply[$i][1]."</li>";
	    }
	    $data .= "</ul>";
	}
	return nl2br($data);
    }
$d = dir("../../data/bug/");

    while($entry=$d->read()) {
        if($entry[0] == '.') continue;
          $dir_ar[] = $entry;

    }
    $d->close();

    array_multisort ($dir_ar,SORT_NUMERIC,SORT_ASC );

    require_once( "LpcData.php");
    require_once( "make_rss_feed.php" );

    $doc = new make_rss_feed;
    $doc->init();
    $doc->title="RevivalWorld Bug Rss!";
    $doc->description="This is RevialWorld Bug Rss!";
    $doc->copyright = "copyright by RevivalWorld";
    $doc->link = "http://www.revivalworld.org/online/rw/bugrss/rss.php";
    $doc->webMaster = "Clode@rw";
    $doc->managingEditor = "rss php package!";

     foreach(array_slice($dir_ar,-20) as $da)
    {
	$ld[$da] = new LpcData;
 	$ld[$da]->file="bug/".$da;       
	$ld[$da]->init("big5");
	$ld[$da]->processLpcData();
	$data = $ld[$da]->data["data"];
	//add_element($title,$des,$link,$auth,$pubDate,$category,$guid)
	$doc->add_element($data["title"],processContent($data["content"],$data["reply"]),"http://www.revivalworld.org",
			$data["author_id"],filectime("bug/".$da),$data["number"],"");
    }

    $doc->makeXML();
    $doc->output_xml();
?>
