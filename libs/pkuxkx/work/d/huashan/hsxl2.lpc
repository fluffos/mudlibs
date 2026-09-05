//binlang
// Jay 3/17/96
inherit ROOM;
void create()
{
	set("short", "后山小路");
	set("outdoors","huashan");
	set("long", @LONG
小路到此已经非常狭窄，两旁的悬崖让你大气都不敢出一口。悬崖上隐隐约
约有几个脚印，好象有人上去过。小路上去就是华山主峰。下边有一小院。
LONG);
	set("exits", ([
		"southdown" : __DIR__"xiaoyuan",
		"northup" : __DIR__"hsxl1",
	]));
    set("room","room5");
	set("item_desc", ([
		"xuanya" : "悬崖非常陡峭，最好不要爬。\n",
		"ya" : "悬崖非常陡峭，最好不要爬。\n",
		"cliff" : "悬崖非常陡峭，最好不要爬。\n",
	]));
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

	if( arg=="up" || arg=="xuanya" ||arg=="ya" ||arg=="cliff" )
	{
		if(me->query_skill("dodge") < 150)
		{
			write("你的轻功不足，爬不上去。\n");
			return 1;
		}
		message_vision("$N小心翼翼的向崖上爬去。\n", me);
		message("vision",
			me->name() + "小心翼翼的向崖上爬去。\n",
			environment(me), ({me}) );
		me->move(__DIR__"xuanya");
		message("vision",
			me->name() + "从下面爬了过来。\n",
			environment(me), ({me}) );
		me->start_busy(2);
		return 1;
	}
}