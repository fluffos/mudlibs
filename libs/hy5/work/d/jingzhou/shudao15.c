// Room: /d/chengdu/shudao15
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "蜀道" NOR );
        set("long", @LONG
你走在以险著称天下的蜀道上，走在这样的路上非要格
外小心，用尽全身气力才行。不多一会儿，你就觉得很累了...
，
LONG
        );
        set("exits", ([
  "northwest" :  __DIR__"shudao16",
  "eastdown" : __DIR__"shudao14",
  
   ]));
        
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
}

int init()
{
	object me;
	int i;
	me=this_player();
	i=(int)me->query("max_qi")/10;
	me->receive_damage("qi", i );
	message("vinson","你费力的走在蜀道上，累的气喘吁吁。\n", me );
}