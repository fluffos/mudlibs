//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "ConnCWall.h"
void create()
{
        set("short", "军营");
        set("long", 
"这里是戍守京师的军营所在，西面是一个大粮仓。\n"

        );
        set("exits", ([
                
                
                
                "northeast" : __DIR__"beicheng",
                "west" : __DIR__"juncang",
                "northwest" : __DIR__"citywall",
                
        ]));
        set("objects", ([
		__DIR__"npc/bing2" : 2,
        
        
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

