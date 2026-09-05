// /d/dalicheng/sl.c 死路
// Jay 3/17/96
#include <room.h>

inherit ROOM;

void create()
{
set("short", "迷魂阵");
       set("long", @LONG
你已经陷入迷魂阵, 永远都出不来了.
LONG
     );
// set("outdoors", "dali");

        set("exits", ([
                "east" : __FILE__,
"west" : __FILE__,
"south" : __FILE__,
"north" : __FILE__,
        ]));
        setup();

//        replace_program(ROOM);
}
void setbackexits()
{
	set("exits/east",__FILE__);
	tell_room(this_object(),"迷魂阵仿佛产生了一些变化，但很快又恢复了原样。\n");
}
void init()
{
	object me = this_player();
	if (me->query_temp("mark/steps") == -10)
	{
		set("exits/east","/d/wuliang/dlroad3");
		remove_call_out("setbackexits");
		call_out("setbackexits",30);
	}
}

int valid_leave(object me, string dir)
{
     if (me->query_temp("mark/steps") == -10)
           me->delete_temp("mark/steps");
	else if ( dir == "east")
            me->add_temp("mark/steps",-1);

/*
     if (me->query_temp("mark/steps") <= -10)
{
me->move("/d/wuliang/dlroad3");
           me->delete_temp("mark/steps");
return notify_fail("你累的精疲力尽, 终于回到了迷魂阵入口处。\n");
        }
*/
        return ::valid_leave(me,dir);
}
