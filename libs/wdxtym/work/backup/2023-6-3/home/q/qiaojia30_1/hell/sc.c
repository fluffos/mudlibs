//by 微笑 dudu66's ednpc tools.
// sc.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","四圣剑城");
	set("long","这里是四圣剑城，创建者尚未设定本地详细描述。");
	set("owner_build","qiaojia30_1");
	set("exits", ([
		"south" : "/data/hell/8/wulinsan1",
	]));
	set("objects", ([
	]));
	setup();
}

