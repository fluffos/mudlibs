//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIC"石城门"NOR);
        set("long", 
"这里是应天府的西面的石城门。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall22",
                "northwest" : __DIR__"citywall21",
                "east" : __DIR__"neicheng/w_street2",
                
        ]));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","east");
        set("dirty",5+random(5));
        set("outdoors", "yingtianfu");
        setup();
   
}

