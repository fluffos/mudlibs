//mroad5.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条小路，两边都种满了美丽的茶花。路的南边有个
阁楼，阁楼的周围也是种满了各种茶花。
LONG
    );

    set("exits", ([
		"northeast" : __DIR__"mroad4",
		"south" : __DIR__"myunjin",
		"west" : __DIR__"mroad6",
    ]));
    
    set("outdoors", "murong");
    setup();

}
