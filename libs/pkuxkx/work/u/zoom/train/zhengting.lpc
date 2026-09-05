//zhengting.c
//by zoom
//2004.3.29

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "正厅");
    set("long", @LONG
这里是新手学堂的正厅，前有一匾，匾上横书「新手学堂」四个大字。
LONG
    );

    set("exits", ([
                "south" : __DIR__"yuan1",
                "north" : __DIR__"yuan2",
                "west" : __DIR__"xiceting",
                "east" : __DIR__"dongceting",
    ]));
    
    set("outdoors", "train");
    setup();

}
