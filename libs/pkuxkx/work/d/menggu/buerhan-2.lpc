inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/climb_to_valley.h"

void create() 
{ 
        set("short", "悬崖");
        set("long", @LONG
这里是一处悬崖，跳下去肯定尸骨无存。
LONG
        );
	
        set("exits", ([ //"eastdown" : __DIR__"",
                        "southdown" : __DIR__"buerhan-3",
                        "northwest" : __DIR__"buerhan-1",
                        //"northup": __DIR__"buerhan",
]));
        set("outdoors", "menggu_e");
		setup();
}
