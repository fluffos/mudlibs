//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", "聚宝门");
        set("long", 
"这里是建康府的正南面的聚宝门，往南通向临安府和建康府南边的无想山。\n"

        );
        set("exits", ([
                
                "west" : __DIR__"citywall",
                "east" : __DIR__"citywall",
                "south" : __DIR__"guandaos1",
                "north" : __DIR__"zhenhuaiqiao",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","north");
        set("outdoors", "yingtianfu");
        setup();
   
}

