//dongce2.c	东侧殿
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","东侧殿");
	set("long",@LONG 
这里是成德殿的东侧殿，是教主练功的地方。地上摆了几个
蒲团，看来是打坐用的。这里十分清洁，也十分安静，显然很少
有人来。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"dadian2",
                  "northwest" : __DIR__"houdian2",
		"east"	: __DIR__"shangyuetai2",
	]));
        set("no_task", 1);
	setup();
}

