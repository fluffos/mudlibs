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
	
        set("exits", ([ //"east" : __DIR__"lvzhou",
                        "south" : __DIR__"xiyu",
                        "west": __DIR__"yeriver2s",
                        "north" : __DIR__"yeriver1",
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