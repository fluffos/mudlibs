// sheku.c

// Modified by mxzhao 2004/04/11 

#define SHENLONG __DIR__"npc/shenlong"

inherit ROOM;

void create()
{
	set("short","蛇窟");
	set("long",@long
这里整年毒雾弥漫，腥臭扑鼻，遍地都是又粗又长的毒蛇和一堆堆白骨，
时常有飞鸟被毒雾熏昏，落下来成为众蛇的美食，群蛇之间的互相吞噬也是
家常便饭，只有那些武功高强的用毒高手才能从这里生离。此处好象没有什
么出路，你可以到处走走(go)看。
long);
	/*set("exits",([
	    "northwest" : __DIR__"treen2",
          "southwest" : __DIR__"trees2",
          "east" : __DIR__"sande",
]));*/

	set("objects",([
		SHENLONG: 1,
		__DIR__"npc/dushe2" : 4,
	]));

	set("outdoors", "神龙岛");
	setup();
}

void init()
{
	object me=this_player();

	if(userp(me) && me->query_skill("poison",1)<100)
	{
		me->apply_condition("sl_poison", (5-((int)me->query_skill("poison",1))/20)*10);
	}

	add_action("do_go", "go");
	add_action("do_bo", "bo");
}

int do_bo(string arg)
{
	object me = this_player();

	if(!living(me))
	{
		return 0;
	}

	if (me->is_busy() || me->is_fighting())
	{
		return 0;
	}

	if(arg != "白骨" && arg != "baigu")
	{
		return 0;
	}
	
	if (random(10) < 3)
	{
		return 0;
	}
	
	foreach (object ob in all_inventory(this_object()))
	{
		if(base_name(ob) == SHENLONG)
		{
			return 0;
		}
	}

	if(random(10) < 2)
	{
		object bg = unew(__DIR__"npc/obj/baogou");

		if(objectp(bg))
		{
			tell_room(this_object(),"忽然有什么东西从一堆白骨中掉了出来。\n");
			bg->move(this_object());
		}
	}
	else
	{
		object she = new(SHENLONG);
		
		she->set("combat_exp", 500000+random(300001));
		she->set("max_qi",6000+random(4001));
		she->set("max_jing",6000+random(4001));
		
		she->set_temp("apply/attack", 80+random(21));
		she->set_temp("apply/defense", 500+random(501));
		she->set_temp("apply/damage", 80+random(21));
		she->set_temp("apply/armor", 500+random(501));
		she->move(this_object());
		
		tell_room(this_object(),"突然从白骨下面窜出一条比刚才更加粗的巨蛇！\n");
	}
	
	return 1;
}

int do_go(string arg)
{
	object me = this_player();

	if(!living(me) )
	{
		return 0;
	}

	if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
	}

	if( arg != "west" 
		&& arg != "east" 
		&& arg != "north" 
		&& arg != "south" )
	{
		return notify_fail("你要往哪里去？\n");
	}

	if(random(10)>=5)
	{
		me->move(__DIR__"treen1");
	}

	return 1;
}
