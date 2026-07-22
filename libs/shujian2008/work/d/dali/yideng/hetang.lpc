// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "河塘");
	set("long", @LONG
塘中荷叶片片，宛如人间仙境，荷花朵朵，赛比西施更升一筹。在荷塘尽
头石桥后坐落一座禅院，气势恢弘，内透王者气度，旁边有座假山，假山侧面
有个洞口，似是个通道(tongdao)。
LONG
	);
	set("outdoors", "桃源县");
	set("exits", ([
		"north" : __DIR__"shiqiao",
		"south" : __DIR__"liang",
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

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	message_vision("$N一毛腰钻进了一条直抵山下的快捷通道。\n", me);
	me->move(__DIR__"caowu");
	tell_room(environment(me), me->name() + "从通道中钻了过来。\n", ({ me }));
	return 1;
}
