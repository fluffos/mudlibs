
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"入川古栈道"NOR);
        set("long", "蜀道难行，自古有云：蜀道难，难于上青天。西南面就是成都了。\n");
        set("exits", ([
               
               "southwest" : __DIR__"guandaoe1",
               "northeast" : __DIR__"shudao2",
                
        ]));
        set("outdoors", "chengdu");
        setup();
   
}


int valid_leave(object me,string dir)
{  
	object pl=this_player();
        if (time() - pl->query_temp("shudao/last_go_time") <= 3+random(3))
        {
            return notify_fail("你小心翼翼往前挪动，遇到艰险难行处，只好放慢脚步。\n");
        }
        else
        {
            pl->set_temp("shudao/last_go_time",time());
        }
    
	return ::valid_leave(me, dir);
}