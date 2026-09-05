// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "东大街");
        set("long", "这里是南昌城的东大街。北面是一户人家，南面就是大名鼎鼎的宁王府。\n");
        set("exits", ([
               "south" : __DIR__"damen",
               "east" : __DIR__"eastgate",
               "west" : __DIR__"guangchang",
               "north" : __DIR__"baifu",
               
                
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
        if (time() - pl->query_temp("ncjob/last_go_time") <= 2)
        {
            return notify_fail("你扛着青砖一步一步地向前挪动。\n");
        }
        else
        {
            pl->set_temp("ncjob/last_go_time",time());
        }
    }
    if (dir=="south"&&me->query_temp("mingtasks/zongrenfu/task")==1)
    {
        return notify_fail("你想了想，还是在当地人中打听一下宁王的口碑吧。\n");
    }
	return ::valid_leave(me, dir);
}


