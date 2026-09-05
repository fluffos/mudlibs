// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"中庭"NOR);
        set("long", "这里是一处巨大的中庭，布道通向内院，四季常绿的草坪，种着两棵巨大的\n古树。\n");
        set("exits", ([
               
               "west" : __DIR__"menfang",
               "east" : __DIR__"mafang",
               "out" : "/d/nanchang/damen",
               
                
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