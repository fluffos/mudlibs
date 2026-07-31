
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"背德城旅店"NOR);
	set("long", BLU @LONG
背叛神的城市，这里生活着的都是魔族和一些妖物，
魔族，背弃神的种族，在几千年的流放下，依然顽强的
生存着。由此可以看出任何种族都有其存在的理由和方
式。你可以在这个地方睡觉??(sleep)，也可以买点吃的(list)
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
                "south" : __DIR__"dong27",
                "north" : __DIR__"dong30",
	]));
         set("objects", ([
              __DIR__"npc/sell3" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
