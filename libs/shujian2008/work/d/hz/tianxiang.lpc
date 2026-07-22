// d/hz/tianxiang.c 鸿昌客栈

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"鸿昌客栈"NOR);
	set("long", @LONG
鸿昌客栈是杭州城里最大的客店了，凡是到杭州来游玩的游客疲劳后都
到这里来小憩，鸿昌客栈的老板非常好客，而且这里的房钱比别处要便宜的
多。你一走进这里，店小二就笑盈盈地迎了过来。墙上挂着一个牌子(paizi)。
LONG
	);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("no_fight",1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"yuemiao",
		"north" : __DIR__"qsddao4",
		"east" : __DIR__"majiu",
		"up" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="鸿昌客栈" && dir == "up" )
		return notify_fail("怎么着，想白住我们鸿昌客栈啊！\n");
	if ((string)me->query_temp("rent_paid")=="鸿昌客栈" && dir == "west" )
		return notify_fail("客官已经付了银子，怎么不住店就走了呢！\n"+
				"旁人还以为小店伺候不周呢！\n");
	return ::valid_leave(me, dir);
}
