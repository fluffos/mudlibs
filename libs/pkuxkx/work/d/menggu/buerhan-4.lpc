inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/climb_to_valley.h"

void create() 
{ 
        set("short", "山崖");
        set("long", @LONG
这里是一处山崖，东面一块平地却被一条深深的裂缝天然分割。
LONG
        );
	
        set("exits", ([ "east" : __DIR__"ding",
                        "northeast" : __DIR__"buerhan-3",
                        "northwest" : __DIR__"buerhan-5",
                        //"northup": __DIR__"buerhan",
]));
        set("outdoors", "menggu_e");
		setup();
}

int valid_leave(object me,string dir)
{
    if (dir=="east"&&me->query("id")!="zine")
    {
        return notify_fail("这条裂缝极深极宽，非人力能渡。\n");
    }
    return ::valid_leave(me,dir);
}