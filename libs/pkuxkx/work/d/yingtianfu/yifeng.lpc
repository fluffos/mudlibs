//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIM"仪凤门"NOR);
        set("long", 
"这里是应天府的西北面的仪凤门。\n"

        );
        set("exits", ([
                
                "southeast" : __DIR__"citywall19",
                "northeast" : __DIR__"citywall18",
                "east" : __DIR__"neicheng/xiaolu",
                
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

