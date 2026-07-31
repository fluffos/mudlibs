// Room: /city/nanmen.c
// YZC 1995/12/04 

#include <ansi.h>

inherit ROOM;


void create()
{
     set("short",RED "南门" NOR);
	set("long", @LONG
	这是岳阳南城门，城墙被当成了广告牌，贴满了花花绿绿各行各业的广告，
官府的告示(gaoshi)因此不太显目。官兵们被近处的欢声笑语所吸引，似乎不是
很认真在执勤。一条笔直的青石板大道向南北两边延伸。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"south" : "/d/road/ryytocs0",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));

	setup();
}
