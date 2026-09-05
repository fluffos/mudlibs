inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", "坡地");
        set("long", @LONG
这里是一处坡地，东面是铁木真领辖的部落，西面是雄伟的圣山——不儿罕山。
西南不儿罕山的余脉有一处悬崖高耸入云。
LONG
        );
	
        set("exits", ([ "westup" : __DIR__"buerhan_hill1",
                        "southeast" : __DIR__"menggubao0",
                        "southwest" : __DIR__"shanqian2",
]));
        set("outdoors", "menggu_m");
		set("objects", ([
        	__DIR__"npc/mumin" : 1,
		]));
		setup();
}
