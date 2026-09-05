inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/climb_to_valley.h"

void create() 
{ 
        set("short", "峭壁");
        set("long", @LONG
这处虽然不高，但路途极为陡峭，稍有不慎，必然跌落下山。
LONG
        );
	
        set("exits", ([ //"eastdown" : __DIR__"buerhan_hill1",
                        "southwest" : __DIR__"buerhan-4",
                        "northup" : __DIR__"buerhan-2",
                        //"northup": __DIR__"buerhan",
]));
        set("outdoors", "menggu_e");
		setup();
}
