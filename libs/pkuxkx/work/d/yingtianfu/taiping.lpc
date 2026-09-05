//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIW"太平门"NOR);
        set("long", 
"这里是应天府的北面的太平门。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"citywall9",
                "west" : __DIR__"citywall10",
                "southeast" : __DIR__"neicheng/shilu",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","southeast");
        set("outdoors", "yingtianfu");
        setup();
   
}

