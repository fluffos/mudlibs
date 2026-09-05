// 雪路
// by steel

inherit ROOM;
void create()
{
	set("short", "雪洞前");
	set("long", @LONG
	路到了这里就消失了,西北是一个小山丘,隐约望去,似乎有个山洞。
LONG
	);
	set("outdoors", "changbai");
        set("exits", ([
		"southeast" : __DIR__"road2",
		"northwest" : __DIR__"hole1",
	]));
	setup();
}

#include "xuedi.h"

int valid_leave(object me, string dir)
{


       if( dir == "northwest" && !userp(me) )
                        return notify_fail("NPC不要乱跑！\n");
       if( dir == "northwest" && userp(me) )
       {
       		if(!me->query_temp("allow_in"))
       		{
         		me->set_temp("allow_in", 1);
	         	return notify_fail("山洞里面似乎充满了危险！你真的要进去吗？\n");
	        }
       }
       me->delete_temp("allow_in");
       return ::valid_leave(me, dir);
}
