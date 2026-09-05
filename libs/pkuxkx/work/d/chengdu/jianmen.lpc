
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "剑门关");
        set("long", @LONG
剑门关位于成都北面的大剑山口，扼守着成都的北大门，大剑山
倚天如剑，峭壁连绵，横亘似城，山口两崖相对如门。
LONG );
        set("exits", ([
               
               "northdown" : __DIR__"shudaon3",
               "southdown" : __DIR__"guandaon1",
                
        ]));
        set("outdoors", "chengdu");
        setup();
   
}

int valid_leave(object me, string dir)
{
	me->set_temp("shudao/last_go_time",time());
	return ::valid_leave(me, dir);
}