//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "刑部库房");
        set("long", 
"这里刑部的衙门的库房。\n"

        );
        set("exits", ([
                
              
                
                
                
                "out" : __DIR__"xing_room2",
                
                
                
        ]));
        
        
        setup();
   
}

void init()
{
	object me=this_player();
	if (me->query_temp("mingtasks/dalisi/task")==2&&present("an juan",me))
	{
		if (present("an juan",me)->query("owner")==me)
		{
			tell_object(me,"你把案卷随意找个地方放(fangzhi)一下就可以了。\n\n");
			return;
		}
	}
}