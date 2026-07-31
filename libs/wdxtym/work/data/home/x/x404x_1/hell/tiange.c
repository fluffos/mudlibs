//by 微笑 dudu66's ednpc tools.
// tiange.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","天阁");
	set("long","这里是天阁，创建者尚未设定本地详细描述。");
	set("owner_build","x404x_1");
	set("exits", ([
		"west" : "/data/hell/3/wulinsi12",
	]));
	set("objects", ([
	]));
	setup();
}

