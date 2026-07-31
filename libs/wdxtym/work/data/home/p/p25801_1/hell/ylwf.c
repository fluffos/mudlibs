//by 微笑 dudu66's ednpc tools.
// ylwf.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","阎罗王府");
	set("long","这里是阎罗王府，创建者尚未设定本地详细描述。");
	set("owner_build","p25801_1");
	set("exits", ([
		"west" : "/data/hell/7/wulinsan7",
	]));
	set("objects", ([
	]));
	set("close_room", 1);
	set("owner_special", 1);
	setup();
}

