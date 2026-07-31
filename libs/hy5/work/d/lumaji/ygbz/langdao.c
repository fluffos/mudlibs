#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "廊道");
        set("long", @LONG
你一走进来便感觉到空间扩阔，由一个小密室
变成可容人直立行走的廊道，笔直往上延伸，尽端
处蒙蒙青光。
LONG );
        set("objects", ([
                 ]));

               set("exits", ([
                "north"  : __DIR__"jingduan",
                                
        ]));

//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

