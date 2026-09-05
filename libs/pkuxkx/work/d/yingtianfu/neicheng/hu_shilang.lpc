//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/ming_player_room";
#include <ansi.h>
#include "hubu.h"
void create()
{
        set("short", CYN"值房"NOR);
        set("long", 
"这里户部侍郎的值房，两位侍郎大人似乎正在讨论着什么。\n"

        );
        set("exits", ([
                
              "out" : __DIR__"hu_room1",
                
                
                
        ]));
        set("depart","户部");
        set("depart_name","depart_hubu");
        set("objects", ([
		__DIR__"npc/hu-shilang" : 1,
        __DIR__"npc/hu-shilang2" : 1,
	    ]));
        setup();
        get_depart_tasks();
}

