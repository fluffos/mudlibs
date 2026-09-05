inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", "牧民部落");
        set("long", @LONG
这里是益兰州内的牧民部落。
LONG
        );
	
        set("exits", ([ "southeast" : __DIR__"gate1",
                        "northwest" : __DIR__"yilan_0",
                        "west" : __DIR__"yilan_2",
                        "north" : __DIR__"yilan_4",
]));
        set("outdoors", "menggu_n");
		set("objects", ([
        	__DIR__"npc/mumin" : 1,
		]));
		setup();
}
