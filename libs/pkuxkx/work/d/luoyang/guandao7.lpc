//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "大官道");
        set("long", @LONG
这是一条宽阔笔直，尘土飞扬的大官道，足可容得下十马并驰。南边
不远是东都洛阳古城的北门，往北直上可以到达洛水。
LONG
        );

        set("exits", ([
               "southup" : __DIR__"chengbeiqiao",  
               "north" : __DIR__"guandao8",         
        ]));
        set("objects", ([

        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

