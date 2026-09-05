// Room: /d/diaoyudao/midong1.c 密洞
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "密洞");
	set("long", @LONG
这里是山崖下的一个密洞，当年韦小宝偕同七个夫人曾在这
里住过，后来才搬到岛中央的军营里。现在洞里既阴暗有潮湿，
并且张结着密集的蜘蛛网，看来很久没人进来过了。
LONG
);

	set("exits", ([
                 "north" : __DIR__"midong2",
		 "out" : __DIR__"dongkou",
            ]));
		
	setup();
	replace_program(ROOM);
}
