//mroad8.c
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
		"southeast" : __DIR__"mroad7",
		"west" : __DIR__"mshishi",
		"northeast" : __DIR__"mzhulin",
    ]));
    
    set("outdoors", "murong");
    setup();

}
