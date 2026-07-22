// Room: /d/huashan/shuitan.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "瀑布底");
	set("long",@LONG
你只觉得水下面黑咕隆咚的......，什么也看不清。
LONG );
	set("cant_hubiao", 1);
	set("objects", ([
	__DIR__"npc/eyu" : 1,
	]));
	setup();
}

void init()
{
        add_action("do_qian",({"qian", "swim", "youyong", "you"}));
}

int do_qian(string arg)
{
	object me=this_player();

	if ( !arg || (arg != "down" && arg != "up" ))
		return notify_fail("你象条鱼般在水里游来游去!\n");

	if (arg =="down") {
		return notify_fail("你想当泥鳅往地下钻呀!\n");
	}
        else {
		message_vision("$N一蹬腿，往上游去。\n", me);
		me->receive_damage("jingli", 50-(int)me->query_skill("dodge", 1)/20);
		me->move(__DIR__"pubu");
		tell_room(environment(me), me->name() + "从水下冒了上来。\n", ({ me }));
		return 1;
	}
	return 1;
}
