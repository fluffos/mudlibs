inherit ROOM; 
#include <ansi.h>

#include "/d/menggu/getarrow.h"
void create() 
{ 
        set("short", "牧民部落");
        set("long", @LONG
这里是益兰州内的牧民部落。
LONG
        );
	
        set("exits", ([ "east" : __DIR__"qianli4",
                        "north" : __DIR__"qianli3",
                        "southwest" : __DIR__"yilan_0",
                        "west" : __DIR__"yilan_1",
                        "south" : __DIR__"yilan_3",
]));
        set("outdoors", "menggu_n");
		set("objects", ([
        	__DIR__"npc/mumin" : 1,
			__DIR__"npc/girl" : 1,
		]));
		setup();
}
