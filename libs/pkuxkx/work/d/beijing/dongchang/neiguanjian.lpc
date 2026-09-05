#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"内官监"NOR);
	set("long",
HIC"内官监掌管木、石、瓦、土、塔材、东行、西行、油漆、婚礼、火药十作，
及米盐库、营造库、皇坛库，凡国家营造宫室、陵墓，并铜锡妆奁、器用暨冰
窨诸事。 \n"NOR
	);

	set("exits", ([
		"south" : __DIR__"shangbaojian",
		"north" : __DIR__"yuyongjian",
//		"east" : __DIR__"citang",
	]));

	setup();
	replace_program(ROOM);
}
