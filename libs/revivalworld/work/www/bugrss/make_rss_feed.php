<?php
class make_rss_feed
{
	var $title = "unknow";
	var $link = "http://localhost";
	var $language = "en";
	var $descripition = " just a test object";
	var $copyright = "no copyright";
	var $docs = "http://backend.userland.com/rss";
	var $generator = "UnKnow";
	var $managingEditor = "php auto make";
	var $webMaster = "unknow";
	var $elements;
	//create xml doc
	var $doc;
	var $ptr;
	function init()
	{
		$this->doc = new DOMDocument("1.0","big5");
		$this->title = "unknow";
		$this->language = "en";
		$this->descripition = " just a test object";
		$this->ptr = 0;
	}
	function makeXML()
	{
		$doc = $this->doc;
		//create the rss element
		$root = $doc->createElement('rss');
		$root = $doc->appendChild($root);
		$root->setAttribute('version','2.0');
		
		//create the channel element
		$channel = $doc->createElement("channel");
		$channel = $root->appendChild($channel);
		
		$basics = array();
		$basics["title"] = $this->title;
		$basics["link"] = $this->link;
		$basics["description"] = $this->description;
		$basics["language"] = $this->language;
		$basics["copyright"] = $this->copyright;
		$basics["docs"] = $this->docs;
		$basics["generator"] = $this->generator;
		$basics["managingEditor"] = $this->managingEditor;
		$basics["webMaster"] = $this->webMaster;
		//"Sat, 05 Feb 2005 23:39:07 EST";
		$basics["lastBuildDate"] = substr(date("l",time()),0,3).date(", d M Y H:i:s T",time());
		
		foreach ($basics as $elementname => $elementvalue)
		{
		 $elementname = $doc->createElement($elementname);
		 $elementname = $channel->appendChild($elementname);
		 $elementname->appendChild($doc->createTextNode($elementvalue));
		}
		
		//clear the array
		unset($basics);
				//loop through each item and add its elements to the tree
		foreach ( $this->elements as $element )
		{
		   //create the item element
		   $item = $doc->createElement("item");
		   $item = $channel->appendChild($item);
		  
		   foreach ( $element as $elementname => $elementvalue )
		   {
		       $elementname = $doc->createElement($elementname);
		       $elementname = $item->appendChild($elementname);
		       $elementname->appendChild($doc->createTextNode($elementvalue));
		   }
		}
	}
		
	function output_xml()
	{
		//output the xml
		header('Content-Type: text/xml');
		echo $this->doc->saveXML();
//		print_r( $this->elements);
	}		
	function add_element($title,$des,$link,$auth,$pubDate,$category,$guid)
	{
		//now create the first feed item
		//instead, you could just pull some items from a db into an elements[] array.
		$i = $this->ptr;
		$this->elements[$i]["title"] = $title;
		$this->elements[$i]["description"] = $des;
		$this->elements[$i]["link"] = $link;
		$this->elements[$i]["author"] = $auth;
		$this->elements[$i]["pubDate"] = substr(date("l",$pubDate),0,3).date(", d M Y H:i:s T",$pubDate);
		$this->elements[$i]["category"] = $category;
		// 不知道幹嘛的
		$this->elements[$i]["guid"] = $guid;
		$this->ptr++;
	}

}

?>
