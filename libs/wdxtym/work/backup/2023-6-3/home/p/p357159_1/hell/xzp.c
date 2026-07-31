//by 微笑 dudu66's ednpc tools.
// xzp.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小帐篷");
	set("long","这里是小帐篷，创建者尚未设定本地详细描述。");
	set("owner_build","p357159_1");
	set("exits", ([
		"east" : "/data/hell/7/wuliner8",
	]));
	set("objects", ([
	]));
	setup();
}

