
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"沼泽"NOR);
        set("long", "这里是按台山附近的一片沼泽，人迹罕至。\n");
        set("exits", ([
               
               "southwest" : __DIR__"yeriver5",
               "northeast" : __DIR__"zaoze3",
               "northwest" : __DIR__"zaoze",
               "southeast" : __DIR__"zaoze",
                
        ]));
        set("outdoors", "menggu");
        set("outdoors", "menggu_w");
        setup();
   
}


int valid_leave(object me,string dir)
{  
	object pl=this_player();
    if (dir=="northwest"||dir=="southeast")
    {
        return notify_fail("你不要命了嘛？直接往沼泽里走？\n");
    }
    else
    {
        if (time() - pl->query_temp("menggu_zhaoze/last_go_time") <= 3+random(2))
        {
            return notify_fail("你小心翼翼往前挪动，生怕陷入沼泽，万劫不复。\n");
        }
        else
        {
            pl->set_temp("menggu_zhaoze/last_go_time",time());
        }
    
	    return ::valid_leave(me, dir);
    }
}