//qroad1.c
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
        "east" : __DIR__"hubian2",
		"west" : __DIR__"qroad2",
		"north" : __DIR__"qroad4",
		"south" : __DIR__"matou",
    ]));
    
    set("outdoors", "murong");
    setup();

}
