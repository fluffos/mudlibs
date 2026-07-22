// Room: /chengdu/cai.c
// oooc: 1998/06/24 

inherit ROOM;

void create()
{
        set("short", "菜场");
	set("long", @LONG
这里是个小菜场，一般成都的居民都到这里买菜。虽然场地不
是很大，但品种还是比较齐全的。所以，周围到也没有第二家。开
菜场的是老大娘，平日喜欢跟人拉拉家常。只见墙角处似乎有个洞。
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"nanjie",
	]));

        set("objects", ([
             __DIR__"npc/oldwomen" : 1,
        ]));

	set("item_desc", ([
        "洞" : "这是一个黑不溜湫的洞，里面不知道有些什么古怪。\n",
	]));
	setup();
}

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

        if( arg=="洞" )
	{
		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
                me->move(__DIR__"ruin1");
                message("vision",
			me->name() + "从洞里走了进来。\n",
                	environment(me), ({me}) );
		return 1;
	}
}	

