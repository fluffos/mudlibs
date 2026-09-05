//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", YEL"金川门"NOR);
        set("long", 
"这里是建康府的北面的金川门。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"citywall",
                "west" : __DIR__"citywall",
                "southeast" : __DIR__"beicheng",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","southeast");
        set("outdoors", "yingtianfu");
        setup();
   
}
