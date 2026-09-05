// /d/dali/mhz1.c
// paladin 02/98
#include <room.h>

inherit ROOM;

void create()
{ 
set("short", "迷魂阵");
       set("long", @LONG
你一旦走进了迷魂阵, 就别想容易的走出去.
LONG
     );
// set("outdoors", "dali");
    
	set("exits", ([
"east" : __DIR__"mhz3",
"west" : __DIR__"sl",
"south" : __DIR__"sl",
"north" : __DIR__"sl",
"northwest" : __DIR__"sl",
"southeast" : __DIR__"sl",
	]));             
        setup();

//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( dir == "east")
            me->add_temp("mark/steps",-1);


     if (me->query_temp("mark/steps") == -10)
{
me->move("/d/dali/dlroad3");
           me->delete_temp("mark/steps");
return notify_fail("你累的精疲力尽, 终于回到了迷魂阵入口处");
     	}

        return ::valid_leave(me,dir);
}
