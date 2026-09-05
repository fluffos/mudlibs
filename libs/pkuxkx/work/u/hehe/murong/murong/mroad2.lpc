//mroad2.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条小路，两边都种满了茶花。
LONG
    );

    set("exits", ([
		"east" : __DIR__"mroad1",
		"west" : __DIR__"mqiao",
    ]));
    
    set("outdoors", "murong");
    setup();

}
