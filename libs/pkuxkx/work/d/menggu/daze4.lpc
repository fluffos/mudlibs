inherit ROOM; 
#include <ansi.h>
#include "daze.h"
void create() 
{ 
        string *names=({"大泽湖边","大泽湖畔","大泽之滨",});
        set("short", names[random(sizeof(names))]);
        set("long", @LONG
这里是大泽的岸边。
LONG
        );
	
        set("exits", ([ "south" : __DIR__"daze5",
                        "northwest" : __DIR__"daze3",
                        "west" : __DIR__"daze",
                        //"east" : __DIR__"angke6",
                        //"south" : __DIR__"daze",
]));
        set("outdoors", "menggu_n");
		setup();
}
