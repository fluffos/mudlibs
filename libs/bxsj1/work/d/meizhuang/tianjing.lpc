// Room: /d/meizhuang/tianjing.c
// By Lklv

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
这是庄内的一个大天井，天井的左右各植有一棵老梅树，枝干如铁，极
是苍劲。南面是一间厅堂，出天井北面方向就是庄门。
LONG
	);
	set("outdoors","梅庄");

	set("exits", ([
		"east" : __DIR__"huilang25",
		"west" : __DIR__"huilang24",
		"south" : __DIR__"hall",
		"north" : __DIR__"door",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "south" && me->query_temp("mz_quest/flag")==3
	&& (objectp(present("ding jian", environment(me)))
	|| objectp(present("shi lingwei", environment(me))) )){
		return notify_fail(CYN"两个家人拦在你的身前道：“" + RANK_D->query_respect(me) + "留步，请随我二人进庄罢。”\n"NOR);
	}
	if (dir == "south" && me->query_temp("mz_quest/go")==1)
		me->set_temp("mz_quest/go",2);

        return ::valid_leave(me, dir);
}