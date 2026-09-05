//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "后巷");
        set("long", 
"这里是张家口的北市的一条小巷，对着一家酒楼，经常有喝醉的人在这里呕\n吐。\n"

        );
        
        set("exits", ([
                "west" : __DIR__"northstreet",
                
        ]));
        /*set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));*/
        set("outdoors", "saiwai");
        setup();
   
}

int vomit(object me)
{
	if (!me)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	message_vision("$N看着满地的呕吐物，忍不住也大吐特吐了起来。\n",me);
	me->set("food",me->max_food_capacity()/10);
	return 1;
}
void init()
{
	object me=this_player();
	if (me->query("food")<me->max_food_capacity()/2)
	{
		return;
	}
	call_out("vomit",1,me);
	return;
}


