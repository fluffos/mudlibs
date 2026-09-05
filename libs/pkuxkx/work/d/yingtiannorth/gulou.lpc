//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "ConnCWall.h"
void create()
{
        set("short", "鼓楼");
        set("long", 
"这里是建康府的鼓楼。一个小厮一直在这里负责打扫。\n"

        );
        set("exits", ([
                
                
                
                "northwest" : __DIR__"beicheng",
                "south" : __DIR__"beimenqiao",
				"north" : __DIR__"citywall",
                
                
        ]));
        set("objects", ([
                __DIR__"npc/xiaosi" : 1,
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

