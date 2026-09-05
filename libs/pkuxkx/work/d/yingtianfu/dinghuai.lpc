//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", BLU"定淮门"NOR);
        set("long", 
"这里是应天府的西北面的定淮门。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall20",
                "northwest" : __DIR__"citywall19",
                "northeast" : __DIR__"neicheng/junying2",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","northeast");
        set("outdoors", "yingtianfu");
        setup();
   
}

