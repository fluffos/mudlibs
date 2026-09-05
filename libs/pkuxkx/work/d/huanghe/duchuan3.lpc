// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19

inherit ROOM;
#include <ansi.h>



void create()
{
	set("short", WHT"羊皮筏"NOR);
	set("long", @LONG
这是一条羊皮筏，在河套地区用来横渡黄河。
LONG
	);
    set("no_task",1);

	set("outdoors", "huanghe");
	setup();
	
}


void init()
{
    int i;
    object * all=all_inventory(this_object());
    object clue;
    for (i=0;i<sizeof(all);i++)
    {
        all[i]->delete_temp("hhallowed");
    }
    
}

#include "event.h"