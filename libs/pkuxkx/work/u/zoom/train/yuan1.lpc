//yuan1.c
//by zoom
//2004.3.29

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小院");
    set("long", @LONG
这是新手学堂的小院，院中山石古拙，溪池清澈，花卉不多，甚是雅致。
LONG
    );

    set("exits", ([
                "south" : __DIR__"gate",
                "north" : __DIR__"zhengting",
                "west" : __DIR__"kefang",
                "east" : __DIR__"road1",
    ]));
    
        set("objects", ([
                __DIR__"npc/baodating" : 1,
        ]));
 
    set("outdoors", "train");
    setup();

}
