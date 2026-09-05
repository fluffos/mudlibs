#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "客店");
         set("long","这是一家价钱低廉的客栈,门口有一块红木" + RED"牌子(paizi)"NOR +"如今襄阳兵荒马乱,住客很少.\n只有过往的江湖客偶尔住住,老板为了维持经营,价钱很便宜,只要5两白银就住一晚.\n");
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n交足10两黄金,随便住.",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"xysouth1",
		"up" : __DIR__"kedian2",
	]));

	setup();
//        "/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent-paid") && !me->query("rent-all") &&dir == "up" )
	return notify_fail("店小二满脸堆笑地走过来说,客官,请您先付店钱.\n");
	return ::valid_leave(me, dir);
}
