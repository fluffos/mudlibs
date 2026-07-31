
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"背德城广场"NOR);
	set("long", BLU @LONG
背叛神的城市，这里生活着的都是魔族和一些妖物，
魔族，背弃神的种族，在几千年的流放下，依然顽强的
生存着。由此可以看出任何种族都有其存在的理由和方
式。这里有个魔法点，你可以记录一下(save)。
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong21",
                "north" : __DIR__"dong23",
                "east" : __DIR__"dong24",
                "west" : __DIR__"dong27",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(3),
         ]));
 set("valid_startroom", "1");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
