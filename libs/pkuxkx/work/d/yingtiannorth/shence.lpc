//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", MAG"神策门"NOR);
        set("long", 
"这里是建康府的正北面的神策门，往北过长江通往中原。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"citywall",
                "west" : __DIR__"citywall",
                "north" : __DIR__"tulun1",
                "south" : __DIR__"beicheng",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","south");
        set("outdoors", "yingtianfu");
        setup();
   
}

