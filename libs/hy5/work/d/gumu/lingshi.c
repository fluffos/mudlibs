// lingshi.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "灵室");
        set("long", @LONG
只见空空旷旷的一座大厅上并列放著五具石棺。凝神细看，见两具石棺棺
盖已密密盖著，原来是古墓派祖师林朝英和小龙女师傅的安身之处。另外二具
的棺盖(guangai)却只推上一半，也不知其中有无尸体。
LONG
        );

        set("exits", ([
                "east" : __DIR__"mishi7",
        ]));

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_push",  ({ "push" }));
}

int do_push (string arg)
{
	object me = this_player();
	
	if( !arg || arg!="guangai" )
		return notify_fail("你要推什么？\n");
	if (me->query("neili") < 1000)
		return notify_fail("你用尽吃奶的力气，可惜棺盖依然纹丝不动。\n");
	me->set("neili", (int)me->query("neili") - 200);
	message_vision(HIY"$N使劲推开了棺盖。\n"NOR, me);
	me->move(__DIR__"shiguan");
	return 1;
}