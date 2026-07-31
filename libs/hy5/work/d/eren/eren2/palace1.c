#include <room.h>
inherit ROOM;
void create()
{
        set("short", "走道");
        set("long", @LONG
“筒子“在洞壁上磕磕碰碰地往下降，洞里的空气变得干燥起来，许
久许久，那“筒子”终于停了，眼前一亮，又出现一道门，一片青蒙蒙的
光线，自门外洒了进来。门里面是条走道，走道不长，可以看到另一端的
门。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace2",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        create_door("north","石门","south",DOOR_CLOSED);
}   
