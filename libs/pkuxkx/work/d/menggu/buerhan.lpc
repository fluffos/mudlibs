inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/getarrow.h"

void create() 
{ 
        set("short", "不儿罕山口");
        set("long", @LONG
这里是不儿罕山口，不儿罕山是一座南北走向的高山，北高南低。
LONG
        );
	
        set("exits", ([ "eastdown" : __DIR__"buerhan_hill1",
                        "westdown" : __DIR__"buerhan_hill2",
                        "southdown" : __DIR__"buerhan-1",
                        "north": __DIR__"buerhan2",
]));
		set("objects", ([
        	__DIR__"npc/mumin" : 1,
		]));
        set("outdoors", "menggu_e");
		setup();
}
