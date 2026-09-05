//mroad8.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条小路，两边都种满了茶花。西面是一间石室。
LONG
    );

    set("exits", ([
		"southeast" : __DIR__"mroad7",
		"west" : __DIR__"mshishi",
		"northeast" : __DIR__"mzhulin",
    ]));
create_door("west", "石门", "east", DOOR_CLOSED);
    set("outdoors", "murong");
    setup();

}
