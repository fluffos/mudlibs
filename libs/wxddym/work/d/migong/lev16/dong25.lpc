
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"炎之魔法商店"NOR);
	set("long", HIY @LONG
  由于火元素的影响，这附近全是砂漠，而这炎之都市正是在
这砂漠绿洲上的一颗明珠!!这里是炎之魔法商店。你想买些
什么呢??(list)
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "north" : __DIR__"dong24",
	]));
         set("objects", ([
              __DIR__"npc/sell" : 1,
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
