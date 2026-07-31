//by 微笑 dudu66's ednpc tools.
// wanxia.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","莞夏");
	set("long","这里是莞夏，创建者尚未设定本地详细描述。");
	set("owner_build","q3043765268_1");
	set("exits", ([
		"north" : "/data/hell/4/wulinsi22",
	]));
	set("objects", ([
	]));
	setup();
}

