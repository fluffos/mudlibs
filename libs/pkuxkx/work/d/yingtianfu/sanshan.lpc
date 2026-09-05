//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIB"三山门"NOR);
        set("long", 
"这里是应天府的西面的三山门。\n"

        );
        set("exits", ([
                
                "south" : __DIR__"citywall25",
                "north" : __DIR__"citywall24",
                "east" : __DIR__"neicheng/sanshanjie",
                
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



