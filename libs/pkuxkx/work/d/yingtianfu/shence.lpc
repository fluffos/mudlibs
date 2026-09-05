//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", MAG"神策门"NOR);
        set("long", 
"这里是应天府的正北面的神策门。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"citywall11",
                "west" : __DIR__"citywall12",
                "north" : __DIR__"tulun1",
                "south" : __DIR__"neicheng/beicheng",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","south");
        set("outdoors", "yingtianfu");
        setup();
   
}

