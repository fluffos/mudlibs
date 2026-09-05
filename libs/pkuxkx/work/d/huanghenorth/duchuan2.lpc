// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "黄河渡船");
	set("long", @LONG
这是一条小船，用来来回横渡黄河。船老大正笑嘻嘻的看着你。
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