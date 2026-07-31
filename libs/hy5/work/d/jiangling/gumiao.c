//Edited by fandog, 02/15/2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "古庙");
	set("long", @LONG
这古庙地处荒僻，年久失修，庙内也无庙祝和尚。神案上满是灰尘
积垢，却有枝粗大的蜡烛(lazhu)放在案上。
LONG );
	set("item_desc", ([
		"lazhu": "一枝粗大的蜡烛，烛泪似乎颇为新鲜，好象刚有人点过。\n"
	]) );
	set("exits", ([
		"east" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/foxiang" : 1,
	]));
	set("coor/x", -1500);
	set("coor/y", -2058);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_dian", "dian");
	add_action("do_dian", "fire");
	add_action("do_open", "qiao");
	add_action("do_open", "open");
}

int do_dian(string arg)
{
	string dir;
	object me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="lazhu" )
	{
		if (! objectp(present("tangshi jianpu", me)))
			return notify_fail("你想点蜡烛干嘛！\n");

		if (! me->query("jinyong/book3"))
			return notify_fail("你没事在这烧书做什么?\n");

		if (me->query("jinyong/book3")==5)
			return notify_fail("你已经取过宝藏了啊?\n");

		if (me->query("jinyong/book3")!=4)
			return notify_fail("你没事在这烧书做什么?\n");


	message("vision", me->name()+"把蜡烛点了起来，突然发现佛像后面有个暗门耶！！\n", environment(me));
		me->set_temp("marks/lazhu", 1);
		return 1;
	}
	else 
		return notify_fail("你想要点什么？\n");
}
int do_open(string arg)
{
	int i;
	object fang;
	object who;
	object where;
	object foxiang, obj,me ;
me = this_player();
where = environment(me);
	who=me;
	if (!objectp(foxiang = present("dafo xiang", this_object())))
		return notify_fail("奇怪，佛像不见了！\n");
	if (foxiang->query("opened"))
		return notify_fail("佛像暗门早给人家打开了！\n");
	if (me->query_temp("marks/lazhu") )
	{
		message("vision", me->name() + "奋力去撬暗门。撬得几下，那暗门渐渐松了。"+me->name()+"伸手指将暗门轻轻起了出来，举烛一照，只见佛像肚里珠光宝气，霭霭浮动，不知这个大肚子之中，藏了有多少珍珠宝贝。\n", environment(me) );
     if(!query("iskillok1"))
      {
      	fang = load_object(__DIR__"npc/wanzhenshan");
	fang->move(environment(who));	
      message_vision("突然从门外突然万震山杀了进来 对$n说道： 宝藏是我的!\n",fang,who);	
	fang->kill_ob(who);
     this_object()->set("iskillok1",1);
     set("iskillok1",1);
      return 1;
      }	

     if(!query("iskillok2"))
      {
      	fang = load_object(__DIR__"npc/yandaping");
	fang->move(environment(who));	
      message_vision("突然从门外突然有两个武林高手杀了进来 对$n说道： 没想到吧 宝藏是我们的了!\n",fang,who);	
	fang->kill_ob(who);
      	fang = load_object(__DIR__"npc/qichangfa");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok2",1);
     set("iskillok2",1);
      return 1;
      }	


        fang = present("yan daping",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision(""+ RANK_D->query_respect(who) +"先把言达平消灭吧。\n",who);
		return 1;
	}

        fang = present("wan zhenshan",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision(""+ RANK_D->query_respect(who) +"先把万震山消灭吧。\n",who);
		return 1;
	}
	

        fang = present("qi changfa",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision(""+ RANK_D->query_respect(who) +"先把戚长发消灭吧。\n",who);
		return 1;
	}	

	if (!who->query_temp("killlc3"))
		return notify_fail("戚长发没死，你无法安心取宝藏！\n");
	if (!who->query_temp("killlc2"))
		return notify_fail("言达平没死，你无法安心取宝藏！\n");
	if (!who->query_temp("killlc1"))
		return notify_fail("万震山没死，你无法安心取宝藏 ！\n");
				

		me->delete_temp("marks/lazhu");
		obj = new("/d/city/obj/goldring");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/necklace");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/goldring");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/necklace");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang);

		foxiang -> set("opened", 1); 
       if(((int)who->query("jinyong/book3")==4))
	{
		obj = new("/clone/book/tangshi_book2");
		obj -> move(foxiang);
		i = 500+random(3000);
		who->set("jinyong/book3",5);
		who->add("combat_exp",i+20000);
		who->add("potential",i*35);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+20000)+"点经验"+
		           chinese_number(i*35)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了连城决的所有任务!"NOR"\n", users());
		who->save();
        }
		return 1;
	}
        else {
		write("黑呼呼的你想干什么？！\n");
		return 1;
        }
}