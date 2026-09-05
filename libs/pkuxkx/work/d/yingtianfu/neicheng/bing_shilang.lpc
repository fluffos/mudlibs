//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/ming_player_room";
#include <ansi.h>
#include "bingbu.h"
void create()
{
        set("short", CYN"值房"NOR);
        set("long", 
"这里兵部侍郎的值房，两位侍郎大人似乎正在讨论着什么。\n"

        );
        set("exits", ([
                
              "out" : __DIR__"bing_room1",
                
                
                
        ]));
        set("depart","兵部");
        set("depart_name","depart_bingbu");
        set("objects", ([
		__DIR__"npc/bing-shilang" : 1,
        __DIR__"npc/bing-shilang2" : 1,
	    ]));
        setup();
        get_depart_tasks();
}

