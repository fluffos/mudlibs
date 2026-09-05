// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "城中心");
        set("long", "这里是南昌城的城中心，南来北往的客流在这里交汇。\n");
        set("exits", ([
               "west" : __DIR__"weststreet",
               "south" : __DIR__"southstreet",
               "north" : __DIR__"northstreet",
               "east" : __DIR__"eaststreet",
               
                
        ]));
        
        set("outdoors", "nanchang");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	object pl=this_player();
    if (present("qing zhuan",pl))
    {
        if (pl->query("max_neili")<1000)
        {
            return notify_fail("你的体力太弱，青砖压得你寸步难行。\n");
        }
        if (time() - pl->query_temp("ncjob/last_go_time") <= 3)
        {
            return notify_fail("你扛着青砖一步一步地向前挪动。\n");
        }
        else
        {
            pl->set_temp("ncjob/last_go_time",time());
        }
    }
	return ::valid_leave(me, dir);
}

