// Room: /d/gaibang/xcandao1.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;



void create()
{
        set("short", "堤坝下");
	set("long", @LONG
外边是黄河南岸，丐帮弟子用一些巧妙的方法的掩住了暗道的出口。
LONG
	);

	set("exits", ([
                        "out" : "/d/huanghe/hhn3",
                        "south" : __DIR__"bjandao4",
	]));

        set("objects",([
                 CLASS_D("gaibang") + "/li-sh" : 1,
        ]));

	setup();
	replace_program(ROOM);
}



