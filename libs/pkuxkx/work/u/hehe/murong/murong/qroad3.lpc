//qroad3.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是岸边用鹅卵石铺成的小路，两边郁郁葱葱的长满了树木。
LONG
    );

    set("exits", ([
        "east" : __DIR__"qroad2",
//		"northwest" : __DIR__"NONE",
		"south" : __DIR__"qinyun",
    ]));
    
    set("outdoors", "murong");
    setup();

}
