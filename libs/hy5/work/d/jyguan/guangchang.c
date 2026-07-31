// Room: /guangchang.c
// Ver 0.1 by Freeze

inherit ROOM;

void create()
{
	set("short", "广  场");
	set("long", @LONG
这里是嘉峪关宽阔的广场，地面用青砖铺成。商贩在这里贸易、落脚停留，这里
熙熙攘攘混乱不堪。
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "jyguan");

//	set("item_desc", ([
//		"shudong" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
//	]));

	set("exits", ([
		"east" : __DIR__"dongmen",
		"south" : __DIR__"nanmen",
		"west" : __DIR__"ximen",
		"north" : __DIR__"beimen",
	]));

//	set("objects", ([
//		__DIR__"npc/xunbu" : 1,
//		__DIR__"npc/liumangtou" : 1,
//		__DIR__"obj/fake-zi" : 1,
//                "/rtm/npc/rtm.c" : 1
//	]));

	setup();
	replace_program(ROOM);
}
/*
void init()
{
        add_action("do_enter", "enter");
	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shudong" ) 
	{
		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
			me->name() + "从洞里走了进来。\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
*/