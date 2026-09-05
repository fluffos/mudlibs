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
	
        set("exits", ([ "southeast" : __DIR__"yilan_0",
                        "north" : __DIR__"qianli2",
                        "east" : __DIR__"yilan_4",
                        "south" : __DIR__"yilan_2",
]));
        set("outdoors", "menggu_n");
		set("objects", ([
        	__DIR__"npc/mumin" : 1,
		]));
		setup();
}
