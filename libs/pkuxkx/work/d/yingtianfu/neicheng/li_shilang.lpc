//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/ming_player_room";
#include <ansi.h>
#include "libu.h"
void create()
{
        set("short", CYN"值房"NOR);
        set("long", 
"这里吏部侍郎的值房，两位侍郎大人似乎正在讨论着什么。\n"

        );
        set("exits", ([
                
              "out" : __DIR__"li_room1",
                
                
                
        ]));
        set("depart","吏部");
        set("depart_name","depart_libu");
        set("objects", ([
		__DIR__"npc/li-shilang" : 1,
        __DIR__"npc/li-shilang2" : 1,
	    ]));
        setup();
        get_depart_tasks();
}

