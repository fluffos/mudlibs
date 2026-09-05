
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"沼泽"NOR);
        set("long", "这里是按台山附近的一片沼泽，人迹罕至。\n");
        set("exits", ([
               
               "southwest" : __DIR__"zaoze",
               "northeast" : __DIR__"zaoze",
               "northwest" : __DIR__"zaoze",
               "southeast" : __DIR__"zaoze",
                
        ]));
        set("no_task",1);
		set("no_robber",1);
        set("outdoors", "menggu");
        set("outdoors", "menggu_w");
        setup();
   
}


int valid_leave(object me,string dir)
{  
	object pl=this_player();
    return notify_fail("你不要命了嘛？直接往沼泽里走？\n");
}