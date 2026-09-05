//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIG"清凉门"NOR);
        set("long", 
"这里是建康府的西面的清凉门，西面出城通往江州，南面有一片湖。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall",
                "northwest" : __DIR__"citywall",
                "westup" : "/d/jiangzhou/guandaoe5",
                "east" : __DIR__"w_street1",
				"south" : __DIR__"laken3",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","east");
        set("outdoors", "yingtianfu");
        setup();
   
}

