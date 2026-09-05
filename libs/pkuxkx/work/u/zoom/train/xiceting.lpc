//zhengting.c
//by zoom
//2004.3.29

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "西侧厅");
    set("long", @LONG
这里是新手学堂的西侧厅。
LONG
    );

    set("exits", ([
                "north" : __DIR__"xixiang",
                "east" : __DIR__"zhengting",
    ]));
    
    set("objects", ([
	__DIR__"npc/xiaofan" : 1,
    ]));

    set("indoors", "train");
    setup();

}
