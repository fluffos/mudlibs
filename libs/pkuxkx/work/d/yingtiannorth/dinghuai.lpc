//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", BLU"定淮门"NOR);
        set("long", 
"这里是建康府的西北面的定淮门。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall",
                "northwest" : __DIR__"citywall",
                "northeast" : __DIR__"junying2",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","northeast");
        set("outdoors", "yingtianfu");
        setup();
   
}

