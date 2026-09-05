// Room: /d/huashan/xuanya2.c

inherit ROOM;

void create()
{
	set("short", "悬崖");
	set("long", @LONG
这儿依然十分陡峭，不过已经强了很多。西边(west)荆棘交加，不知道悬崖
的那边是哪里。
LONG);
	set("exits", ([
		"down" : __DIR__"xuanya",
	]));
    set("no_hsnewbiejob",1);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me = this_player();;

	if( !arg || arg=="" ) return 0;

	if(me->is_busy() || me->is_fighting())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if( arg=="west" )
	{
		if(me->query_skill("dodge") < 150)
		{
			write("你的轻功不足，爬不过去。\n");
			return 1;
		}
		message_vision("$N小心翼翼的顺着长藤向西边爬去。\n", me);
		message("vision",
			me->name() + "绕过了荆棘，从西边的悬崖爬了下去。\n",
			environment(me), ({me}) );
		me->move(__DIR__"siguoya");
		message("vision",
			me->name() + "小心翼翼的顺着长藤从东边爬了过来。。\n",
			environment(me), ({me}) );
		me->start_busy(4);
		return 1;
	}
}