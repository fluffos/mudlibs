// By River 2002.6.3

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
	set("short", HIG"茅屋"NOR);
	set("long", @LONG
这里是一间由竹子搭成的茅屋，屋内摆设简朴，看来是渔人休息的小茅屋，
在墙角放着一艘小铁舟和一对铁桨。
LONG
	);

	set("exits", ([
		"east" : __DIR__"pubu",
	]));

	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "tongdao" ) return 0;

	if ( me->query("family/master_name") != "一灯大师") return 0;

	if ( is_wanted(me)) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	message_vision("$N一毛腰钻进了一条直抵山上的快捷通道。\n", me);
	me->move(__DIR__"hetang");
	tell_room(environment(me), me->name() + "从通道中钻了过来。\n", ({ me }));
	return 1;
}
