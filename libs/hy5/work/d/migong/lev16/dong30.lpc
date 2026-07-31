
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"炎之斗技场"NOR);
	set("long", HIY @LONG
  由于火元素的影响，这附近全是砂漠，而这炎之都市正是在
这砂漠绿洲上的一颗明珠!!这里是炎之斗技场。你可以在这个地方
挑战这个世界的各种怪物!!
LONG NOR);
set("magicroom",1);
set("magicset",1);

set("sleep_room",1);
	set("exits", ([
                "south" : __DIR__"dong29",
	]));
         set("objects", ([
              __DIR__"npc/lev"+(random(5)+5) : 1,
              __DIR__"npc/lev"+(random(6)+4) : 1,
              __DIR__"npc/lev"+(random(8)+2) : 1,
              __DIR__"npc/lev"+(random(9)+1) : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
