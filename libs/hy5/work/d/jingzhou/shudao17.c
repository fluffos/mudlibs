// Room: /d/chengdu/shudao17
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "蜀道" NOR );
        set("long", @LONG
你走在以险著称天下的蜀道上，道路由东上山，异常难行。由西而
下，然而上山容易下山难，也不见得好走，总之走在这样的路上非要格
外小心，用尽全身气力才行。不多一会儿，你就觉得很累了...
，
LONG
        );
        set("exits", ([
  "westdown" :  __DIR__"shudao18",
  "eastup" : __DIR__"shudao16",
  
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