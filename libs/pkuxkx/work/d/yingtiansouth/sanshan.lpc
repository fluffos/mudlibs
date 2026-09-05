//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIB"三山门"NOR);
        set("long", 
"这里是建康府的西面的三山门，出城不远是一片大湖。\n"

        );
        set("exits", ([
                
                "south" : __DIR__"citywall",
                "north" : __DIR__"citywall",
                "east" : __DIR__"sanshanjie",
				"west" : __DIR__"lakes3",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","east");
        set("outdoors", "yingtianfu");
        setup();
   
}



