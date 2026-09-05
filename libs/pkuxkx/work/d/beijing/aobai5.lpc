// Room: /city2/aobai5.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"鳌府厨房"NOR);
	set("long",
HIC"一进门，一股香气扑鼻而来，熏得你直流口水。灶台上满是油烟，
一个肥肥胖胖的家伙正在炒菜,一看就象个大厨师。\n"NOR
	);
	set("exits", ([
		"south" : __DIR__"aobai3",
	]));
	set("objects", ([
		__DIR__"npc/chushi" : 1,
	]));
	setup();
	replace_program(ROOM);
}



