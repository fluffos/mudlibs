//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"户部衙门"NOR);
        set("long", 
"这里户部衙门的大门。\n"

        );
        set("exits", ([
                
              
                
                
                "southwest" : __DIR__"changanjie1",
                "enter" : __DIR__"hu_garden",
                
                
                
        ]));
        
        set("objects", ([
		__DIR__"npc/bing4" : 2,
	    ]));
        setup();
   
}

int valid_leave(object me,string dir)
{
    if (!userp(me)&&dir=="southwest"&&!me->query("mingpin"))
    {
        return notify_fail("\n");
    }
    if (dir=="enter"&&!me->query("mingpin")&&!me->query("ming/tj/pin")&&!present("entry permit",me)&&!me->query("mingjiaonewbiejob/daming")&&!me->query_temp("mingtasks/libu/theone"))
    {
        return notify_fail(this_object()->query("short")+"闲杂人等，不得入内。\n");
    }
    return ::valid_leave(me,dir);
}
