// Room: innercityn.c
// edit by zine Aug 21 2010
#include <ansi.h>
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "瓮城");
	set("long", @LONG
这里是襄阳城北的瓮城，进来后你点燃了火折子。周围一片明亮，你发现两
侧的墙面有些奇怪。你再仔细观察周围地形，不由心里暗叹：一夫当关，万夫莫
开。莫过于此。真是一个绝好的伏击地点。你熄灭了火折子。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"northgate",
        "up": __DIR__"northtower",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_east", "east");
    add_action("do_west", "west");
	::init();
}

int do_east()
{
	object me;
    me = this_player();
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
		}
	else
		{
			tell_object(me,HIY"你福至心灵，从墙缝中钻了过去。\n"NOR);
			me->add_busy(random(2));
			tell_room(environment(me), me->name() + "一闪身就不见了，似乎你眼花了一下。\n"NOR, ({ me }));
			me->move(__DIR__"kuijiakun");
			return 1;
		}
}

int do_west()
{
	object me;
    me = this_player();
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
		}
	else
		{
			tell_object(me,HIY"你福至心灵，从墙缝中钻了过去。\n"NOR);
			me->add_busy(random(2));
			tell_room(environment(me), me->name() + "一闪身就不见了，似乎你眼花了一下。\n"NOR, ({ me }));
			me->move(__DIR__"bingqikun");
			return 1;
		}
}

