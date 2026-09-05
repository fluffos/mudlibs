//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/ming_player_room";
#include <ansi.h>
#include "xingbu.h"
void create()
{
        set("short", CYN"值房"NOR);
        set("long", 
"这里刑部侍郎的值房，两位侍郎大人似乎正在讨论着什么。\n"

        );
        set("exits", ([
                
              "out" : __DIR__"xing_room1",
                
                
                
        ]));
        set("depart","刑部");
        set("depart_name","depart_xingbu");
        set("objects", ([
		__DIR__"npc/xing-shilang" : 1,
        __DIR__"npc/xing-shilang2" : 1,
	    ]));
        setup();
        get_depart_tasks();
}

