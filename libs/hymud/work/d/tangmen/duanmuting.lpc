// Room: /d/tangmen/duanmuting.c 

inherit ROOM;

void create()
{
	set("short", "断木亭");
	set("long", @LONG
	这里是断木亭。堆放了许多粗大的树干，有几个唐门弟子居然在用手掌劈木
柴，累得满头大汗。往北走就是厨房，有一阵阵饭菜的香气传来。
LONG
	);

	set("exits", ([
		"north" : __DIR__"chufang",
		"west" : __DIR__"changlang16",
		"east" : __DIR__"guajiantang",
	]));

	
	set("objects",([

		__DIR__"npc/tang_meng" : 1,

	]));

	 setup();
}

void init()
{
	add_action("do_pi", "pi");
	
}


int do_pi(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "chai" ) )
		return notify_fail("你要干什么？\n");
		
	me->receive_damage("qi", 20);

	message_vision("$N正用力劈砍着树干。\n", me);

	if ( (int)me->query_skill("strike", 1) < 60)
	{
		me->improve_skill("strike", me->query("int"));
		write("你劈砍了一会儿树干，觉得自己的掌力好象强了一点。\n");
		return 1;
	}

	write("你的掌力已经不错了，还是让其他人来练练吧。\n");

	return 1;
}

