//tdiaoyu.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "钓鱼台");
    set("long", @LONG
这是一块邻水的空地，微风吹来，湖面上鳞光闪烁，此地格
外幽静，是个钓鱼静休的好地方。
LONG
    );

    set("exits", ([
		"northeast" : __DIR__"troad3",
    ]));
        set("objects",([
          "/clone/npc/camel1": 0,
        ]));
        set("couldfish",1);
        set("resource/water", 1);
    
    set("outdoors", "murong");
    setup();

}
