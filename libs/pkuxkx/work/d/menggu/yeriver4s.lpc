inherit ROOM; 
#include <ansi.h>
#include "swim_north.h"

void create() 
{ 
        set("short", "也儿的石河南岸");
        set("long", @LONG
这里是也儿的石河的南岸。
LONG
        );
	
        set("exits", ([ "southeast" : __DIR__"yeriver3s",
                        "south" : __DIR__"xiyu",
                        "north" : __DIR__"yeriver4",
]));
        set("outdoors", "menggu_w");
		setup();
}
/*int valid_leave(object me,string dir)
{
    if (dir=="south")
    {
        return notify_fail("西域、昆仑山部分暂未开放。\n");
    }
    return ::valid_leave(me,dir);
}*/