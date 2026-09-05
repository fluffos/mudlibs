
// laoban.c
// 不让vast 定位 by yhzzyahoo

inherit NPC;
inherit F_DEALER;
int ask_map();

void create()
{
	set_name("胡"+chinese_number(random(19)+1), ({ "sui cong"}) );
	set("gender", "男性" );
	set("age", 30);
	set("long",
		"这是胡一刀的亲信手下，跟了胡一刀有10多年了。\n");

	set("combat_exp", 3000);
	set("attitude", "friendly");
	set("dontseekme",1);//不让vast找

	set("shen_type",1);
    set("random_npc",1);
	set("score",500);
	set("inquiry",([
		"藏宝图" :  (: ask_map :)
	   ]));
	setup();

  carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 2);
	call_out("do_leave", 1800);
}

void unconcious()
{
  die();
}

void die()
{
  this_object()->set("eff_qi",this_object()->query("max_qi"));
  this_object()->set("qi",this_object()->query("max_qi"));
  this_object()->set("eff_jing",this_object()->query("max_jing"));
  this_object()->set("jing",this_object()->query("max_jing"));
  return;
}

void do_leave()
{
        if(!this_object())
                return;
        message_vision("$N看了看天色，自言自语道：“天色不早了，得去干活了。”\n", this_object());
        destruct(this_object());
}

int ask_map()
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
	  "/newbiequest/huyidao/hyd9_config"}), *delmaze;
	object me=this_player(), ob=this_object(), obm, killer;
	int lp,idx;
	
	if ( ob->query("quester") != me->query("id") )
		return notify_fail("家丁很困惑地打量了你一下，甩头就走开了。\n");
	
	if ( !me->query("yidao/on_job") ||
		   me->query("yidao/questid")!="maze" )
		return notify_fail("家丁很困惑地打量了你一下，甩头就走开了。\n");
	
	if ( ob->query("clone_maze") )
		return notify_fail("家丁很困惑地打量了你一下，甩头就走开了。\n");
	
	delmaze=({});
	for(lp=0;lp<sizeof(mazeList);lp++)
	{
		if ( objectp(obm=find_object(mazeList[lp])) )
		{
			if ( wizardp(me) && objectp(obm->query("owner")) )
				tell_object(me, sprintf("测试: %s, %O, %O\n", mazeList[lp], obm->query("owner"), environment(obm->query("owner")) ) );
			
			if ( objectp(obm->query("owner")) &&
				   environment(obm->query("owner"))->query("outdoors")=="hydmaze" )
			{
			  delmaze=delmaze+({mazeList[lp]});
			  continue;
			}
		}
	}
	
	mazeList=mazeList-delmaze;
/*    if(sizeof(mazeList) == 0)
    {
        mazeList = delmaze;
    }*/
  if ( !mazeList )
  {
  	tell_object(me, "所有迷宫都被人占用，请稍等！\n");
		return 1;
	}
	
  idx=random(sizeof(mazeList));

	if ( !objectp(obm=find_object(mazeList[idx])) )
	{
		if ( !objectp(obm=load_object(mazeList[idx])) )
		{
			tell_object(me, "所有迷宫都被人占用，请稍等！\n");
			return 1;
		}
	}
		
	obm->set("vtime",time());
	obm->set("froom",ob->query("where"));
	obm->init_virtualMap();
	obm->set("owner", me);
	killer=new(__DIR__"killer7");
	killer->do_copy(me);
	killer->set("hyd/step",1);
	killer->move(mazeList[idx]+"/0_1");
	killer=new(__DIR__"killer7");
	killer->do_copy(me);
	killer->set("hyd/step",2);
	killer->move(mazeList[idx]+"/0_3");
	killer=new(__DIR__"killer7");
	killer->do_copy(me);
	killer->set("hyd/step",3);
	killer->move(mazeList[idx]+"/0_5");
	killer=new(__DIR__"killer7");
	killer->do_copy(me);
	killer->set("hyd/step",4);
	killer->move(mazeList[idx]+"/0_7");
	killer=new(__DIR__"killer7");
	killer->do_copy(me);
	killer->set("hyd/step",5);
	killer->move(mazeList[idx]+"/0_out");
	tell_object(me,"我发现附近的小树林里面藏着一伙盗宝人，从他们身上可能会获得线索。我这就带你过去。\n");
	me->move(sprintf("%s/0_entry", mazeList[idx]) );
	me->set_temp("yidao/maze",obm);
	me->set_temp("yidao/maze_time", time());
	ob->set("clone_maze",1);
	return 1;
}