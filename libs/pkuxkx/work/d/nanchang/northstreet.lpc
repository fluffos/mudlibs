// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "北大街");
        set("long", "这里是南昌城的北大街。两旁店铺林立。\n");
        set("exits", ([
               "west" : __DIR__"kedian",
               "north" : __DIR__"northgate",
               "south" : __DIR__"guangchang",
               "east" : __DIR__"biaoju",
               
                
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
        if (time() - pl->query_temp("ncjob/last_go_time") <= 4)
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
