// Room: /d/gaochang/zoulang1.c

inherit ROOM;


string look_writing();


void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是殿堂走廊。房顶一侧支在南面的高墙上，另一侧则与
北边殿堂的屋顶相连。彩梁画栋，连顶棚也用彩漆绘满了各种
飞天的图形，每幅画似乎都在诉说一个娓娓动人的佛经故事。南
边墙上题着一个字(writing)。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"wroom3",
		"northeast" : __DIR__"zoulang2",
	]));


	setup();
}




void init()
{
	add_action("do_study", "study");
}


int do_study(string arg)
{
	object me;
	int    jing_cost;

	me = this_player();

	if ( !arg || ( arg != "qiangbi" ) )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	jing_cost = 0;
	if((int)me->query("jing") < jing_cost)
		return notify_fail("你现在精神无法集中！\n");

	me->add("jing", jing_cost);

	message_vision("$N正专心研读墙壁上的古怪图形。\n", me);

//	switch( random(5) ) 
//	{
//	    case 0:
		if ( (int)me->query_skill("force", 1) < 220)
		{
			me->improve_skill("force", me->query("int"));
			write("你对着墙壁琢磨了一回儿，似乎对基本内功有点心得。\n");
			me->set_temp("stone_learned",1);
		}


	if ( !me->query_temp("stone_learned") )
	{
		write("你对着墙壁琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}