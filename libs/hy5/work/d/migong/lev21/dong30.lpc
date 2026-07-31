
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"背德城斗技场"NOR);
	set("long", BLU @LONG
背叛神的城市，这里生活着的都是魔族和一些妖物，
魔族，背弃神的种族，在几千年的流放下，依然顽强的
生存着。由此可以看出任何种族都有其存在的理由和方
式。这里是斗技场。你可以在这个地方挑战这个世界的各种怪物!!
LONG NOR);

set("magicroom",1);set("outdoors","migong");
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
