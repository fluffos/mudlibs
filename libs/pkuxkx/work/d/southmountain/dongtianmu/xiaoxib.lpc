// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "溪边");
	set("long", @LONG
这里是从天目山山涧流淌下来的一条小溪的岸边，水却不深，也许你可以涉
水(sheshui)到对岸。
LONG
	);
        set("outdoors", "dongtianmu");

	set("exits", ([
		"northeast" : __DIR__"xiaoxi",
		"south" : __DIR__"xiaoxia",
		//"northeast" : __DIR__"wall1",
		//"west" : __DIR__"wall1",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}

void init()
{
	add_action("do_ss","sheshui");
}

int do_ss()
{
	object me=this_player();
	if (me->is_busy()||me->is_fighting())
	return notify_fail("你正忙着呢。\n");
	message_vision(HIC+"$N"+HIC+"踏入小溪，向着西面走去。\n"+NOR,me);
	me->move("/d/southmountain/xitianmu/xiaoxic");
	me->add_busy(2);
	return 1;
}

