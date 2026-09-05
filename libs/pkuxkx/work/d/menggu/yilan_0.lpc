inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", "广场");
        set("long", @LONG
这里是益兰州的一处广场，牧民庆祝时候载歌载舞的地方。
LONG
        );
	    set("valid_startroom", 1);

        set("exits", ([ "southeast" : __DIR__"yilan_3",
                        "northeast" : __DIR__"yilan_4",
                        "northwest" : __DIR__"yilan_1",
                        "southwest" : __DIR__"yilan_2",
]));
		set("objects", ([
        	__DIR__"npc/banker" : 1,
			__DIR__"npc/lieren" : 1,
		]));
        set("outdoors", "menggu_n");
		setup();
}
