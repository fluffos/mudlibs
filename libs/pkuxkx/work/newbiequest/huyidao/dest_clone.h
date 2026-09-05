//清理垃圾文件

void dest_clone()
{
  string *mazeList=({
		"/newbiequest/huyidao/hyd0_config",
		"/newbiequest/huyidao/hyd1_config",
		"/newbiequest/huyidao/hyd2_config",
		"/newbiequest/huyidao/hyd3_config",
		"/newbiequest/huyidao/hyd4_config",
		"/newbiequest/huyidao/hyd5_config",
		"/newbiequest/huyidao/hyd6_config",
		"/newbiequest/huyidao/hyd7_config",
		"/newbiequest/huyidao/hyd8_config",
	  "/newbiequest/huyidao/hyd9_config"});
	object *exobj, *vob, obm, *eob, *oob, pl;
	int lp;
  
  exobj=({});
	for(lp=0;lp<sizeof(mazeList);lp++)
	{
		if ( objectp(obm=find_object(mazeList[lp])) )
		{
			pl=obm->query("owner");
			if ( objectp(pl) &&
				   environment(pl)->query("outdoors")!="hydmaze" )
			  obm->delete("owner");
/*			
			if ( (vob=obm->query("vroom")) &&
				   arrayp(vob) &&
				   objectp(vob[0]) )
			  exobj=exobj+vob;
			
			if ( arrayp(vob) && !vob[0] )
				obm->delete("vroom");*/
		}
	}
	
/*	eob=children(__DIR__"enter");
	oob=children(__DIR__"out");
	eob=eob-exobj;
	oob=oob-exobj;
	if ( sizeof(eob)<30 ||
		   sizeof(oob)<30 )
	  return;
	for(lp=0;lp<sizeof(eob);lp++)
	  if ( time()-eob[lp]->query("ctime") >=900 )
	    destruct(eob[lp]);
	for(lp=0;lp<sizeof(oob);lp++)
	  if ( time()-oob[lp]->query("ctime") >=900 )
	    destruct(oob[lp]);*/
}  
	  
//初始化动态地图  
int init_virtualMap()
{
	object ob1,ob2, ob=this_object(),*obl;

  ob->virtualRoomDestruct(ob->query("froom"));
/*  if ( (obl=ob->query("vroom"))&&
  	   arrayp(obl) &&
  	   objectp(obl[0]) )
  {
  	destruct(obl[0]);
  	destruct(obl[1]);
  }
  
  ob1=new(__DIR__"enter");
  ob2=new(__DIR__"out");
  ob1->set("ctime", time());
  ob2->set("ctime", time());
  if ( stringp(ob->query("froom")) )
  	ob2->set("exits/east", ob->query("froom"));
  virtualSetting["entry"]["file"]=({ob1});
  virtualSetting["out"]["file"]=({ob2});*/
	create_virtualMap(10+random(3),virtualSetting,0,"middle");
  //ob->set("vroom",({ob1,ob2}));
  dest_clone();
  return 1;
}