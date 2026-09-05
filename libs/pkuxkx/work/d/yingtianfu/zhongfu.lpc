//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", CYN"钟阜门"NOR);
        set("long", 
"这里是应天府的西北面的钟阜门。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall16",
                "northwest" : __DIR__"citywall17",
                "south" : __DIR__"neicheng/junying2",
                
        ]));

        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","south");
        set("dirty",5+random(5));
        set("outdoors", "yingtianfu");
        setup();
   
}
