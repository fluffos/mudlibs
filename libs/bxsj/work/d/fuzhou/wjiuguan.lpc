// Room: d/fouzhou/wjiuguan.c
// lklv 2001.9.7

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","小酒馆");
        set("long", @LONG
这是一家路边小酒馆，以卖酒为主，捎带一些零食。因为路上过往的客人
不是很多，所以生意也很清淡。偶尔会有些到附近郊游的城里人光顾，这里才
热闹起来。一个老头正在檫桌子。
LONG
        );

        set("exits", ([
                "east" : __DIR__"wroad2",
        ]));

        set("objects", ([
                __DIR__"npc/sa" : 1,

        ]));

	setup();
}
