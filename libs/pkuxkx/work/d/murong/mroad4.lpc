//mroad4.c
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
		"northwest" : __DIR__"mhuadi1",
		"southwest" : __DIR__"mroad5",
		"east" : __DIR__"mroad3",
    ]));
    
    set("outdoors", "murong");
    setup();

}
