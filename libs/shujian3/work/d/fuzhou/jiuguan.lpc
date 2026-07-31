// Room: d/fouzhou/jiuguan.c
// lklv 2001.9.7

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","酒馆");
        set("long", @LONG
这是一家小酒馆，只卖一些简单的饭食，捎带卖酒。往来的客人大多都不
是很挑剔，所以店里的生意还过的去。这里的老板整天不露面，有人传说他是
一个退隐的江洋大盗。平日里只有一位年轻的跑堂忙碌着。
LONG
        );

        set("exits", ([
                "west" : __DIR__"dongxiang",
        ]));

        set("objects", ([
                __DIR__"npc/paotang" : 1,

        ]));

	setup();
}
