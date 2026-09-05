//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIG"清凉门"NOR);
        set("long", 
"这里是应天府的西面的清凉门。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall21",
                "northwest" : __DIR__"citywall20",
                "westup" : "/d/jiangzhou/guandaoe5",
                "east" : __DIR__"neicheng/w_street1",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","east");
        set("outdoors", "yingtianfu");
        setup();
   
}

