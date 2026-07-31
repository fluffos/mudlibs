
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"炎之都市"NOR);
	set("long", HIY @LONG
  由于火元素的影响，这附近全是砂漠，而这炎之都市正是在
这砂漠绿洲上的一颗明珠!!附近人来人往，叫卖声，说话声，
吵成一片。这里是城市的中央广场。
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "east" : __DIR__"dong22",
                "west" : __DIR__"dong33",
		"south" : __DIR__"dong28",
                "north" : __DIR__"dong29",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
