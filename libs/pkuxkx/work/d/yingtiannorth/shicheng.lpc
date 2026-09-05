//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIC"石城门"NOR);
        set("long", 
"这里是建康府的西面的石城门，城外是一片美丽的大湖。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall",
                "northwest" : __DIR__"citywall",
                "east" : __DIR__"w_street2",
				"southwest" : __DIR__"lakee3",
                
        ]));
        set("objects", ([
		__DIR__"npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","east");
        set("dirty",5+random(5));
        set("outdoors", "yingtianfu");
        setup();
   
}

