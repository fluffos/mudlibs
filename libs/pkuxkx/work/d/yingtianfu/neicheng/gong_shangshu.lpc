//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/ming_player_room";
#include <ansi.h>
#include "gongbu.h"
void create()
{
        set("short", HIW"值房"NOR);
        set("long", 
"这里工部尚书的值房，太师椅后面端坐着一位中年人。\n"

        );
        set("exits", ([
                
              "out" : __DIR__"gong_room1",
                
                
                
        ]));
        set("depart","工部");
        set("depart_name","depart_gongbu");
        set("objects", ([
		__DIR__"npc/gong-shangshu" : 1,
	    ]));
        setup();
        get_depart_tasks();
}

