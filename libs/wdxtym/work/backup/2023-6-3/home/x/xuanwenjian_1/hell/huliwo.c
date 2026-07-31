//by 微笑 dudu66's ednpc tools.
// huliwo.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","狐狸窝");
	set("long","这里是狐狸窝，创建者尚未设定本地详细描述。");
	set("owner_build","xuanwenjian_1");
	set("exits", ([
		"west" : "/data/hell/5/wulinsan27",
	]));
	set("objects", ([
	]));
	setup();
}

