//Zine 25 Nov 2010


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江南岸，远远向北望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "northwest" : __DIR__"cjn3",
             "southeast" : __DIR__"cjn1",
        ]));
        set("outdoors", "changjiang");

        setup();
}
void init()
{
	object me=this_player(),chai;
	if (me->query_temp("shediaoquest/kanglong/start")==12)
	{
		chai=new(__DIR__"obj/chai");
		chai->move(me);
		message_vision("$N在路边捡了几节柴火。\n",me);
		me->set_temp("shediaoquest/kanglong/start",13);
	}
	return;
}

