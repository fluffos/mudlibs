//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>


void create()
{
        set("short", HIR"兵部衙门"NOR);
        set("long", 
"这里兵部衙门的大门。\n"

        );
        set("exits", ([
                
              
                
                
                "north" : __DIR__"changanjie2",
                "enter" : __DIR__"bing_garden",
                
                
                
        ]));
        
        set("objects", ([
		__DIR__"npc/bing4" : 2,
	    ]));
      
        setup();
}

int valid_leave(object me,string dir)
{
    if (!userp(me)&&dir=="north"&&!me->query("mingpin"))
    {
        return notify_fail("\n");
    }
    if (dir=="enter"&&!me->query("mingpin")&&!me->query("ming/tj/pin")&&!present("entry permit",me)&&!me->query("mingjiaonewbiejob/daming")&&!me->query_temp("mingtasks/libu/theone"))
    {
        return notify_fail(this_object()->query("short")+"闲杂人等，不得入内。\n");
    }
    return ::valid_leave(me,dir);
}


