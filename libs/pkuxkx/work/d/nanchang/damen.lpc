// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", CYN"宁王府大门"NOR);
        set("long", "这里是南昌城的的藩王，宁王的府邸大门。几个士兵正在巡逻。\n");
        set("exits", ([
               
               "north" : __DIR__"eaststreet",
               "enter" : __DIR__"ning/zhongting",
               
                
        ]));
        
        
        setup();
   
}

/*void init()
{
    add_action("do_go","go");
}

int do_go(string dir)
{
	object pl = this_player();
    if (present("qing zhuan",pl))
    {
    
        if(time() - pl->query_temp("ncjob/last_go_time") <= 3)
        {
            write("你扛着青砖一步一步地向前挪动。\n");
            return 1;
        }
        else
	    {
            pl->set_temp("ncjob/last_go_time",time());
	        return 0;
        }
    }
}*/