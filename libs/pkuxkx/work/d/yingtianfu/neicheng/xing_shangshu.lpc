//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/ming_player_room";

#include <ansi.h>
#include "xingbu.h"
void create()
{
        set("short", HIW"值房"NOR);
        set("long", 
"这里刑部尚书的值房，太师椅后面端坐着一位中年人。\n"

        );
        set("exits", ([
                
              "out" : __DIR__"xing_room1",
                
                
                
        ]));
        set("depart","刑部");
        set("depart_name","depart_xingbu");
        set("objects", ([
		__DIR__"npc/xing-shangshu" : 1,
	    ]));
        setup();
        get_depart_tasks();
}

