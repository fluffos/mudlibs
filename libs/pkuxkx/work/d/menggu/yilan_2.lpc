inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", "牧民部落");
        set("long", @LONG
这里是益兰州内的牧民部落。
LONG
        );
	
        set("exits", ([ "northeast" : __DIR__"yilan_0",
                        "southwest" : __DIR__"zaoze1",
                        "east" : __DIR__"yilan_3",
                        "north" : __DIR__"yilan_1",
]));
        set("outdoors", "menggu_n");
		set("objects", ([
        	__DIR__"npc/mumin" : 1,
		]));
		setup();
}
