//by 微笑 dudu66's ednpc tools.
// jia.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","我的草原");
	set("long","这里是我的草原，创建者尚未设定本地详细描述。");
	set("owner_build","houyang1997_1");
	set("exits", ([
		"west" : "/data/hell/7/wuliner6",
	]));
	set("objects", ([
	]));
	setup();
}

