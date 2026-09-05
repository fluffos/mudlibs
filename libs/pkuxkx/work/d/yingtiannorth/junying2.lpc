//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "ConnCWall.h"
void create()
{
        set("short", "军营");
        set("long", 
"这里是戍守京师的军营所在，扼守西北三门，东面是一个大粮仓。\n"

        );
        set("exits", ([
                
                
                
                "east" : __DIR__"juncang",
                "northwest" : __DIR__"xiaolu",
                "north" : __DIR__"zhongfu",
                "southwest" : __DIR__"dinghuai",
				"west" : __DIR__"citywall",
                
                
        ]));
        set("objects", ([
		__DIR__"npc/bing3" : 2,
        
        
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

