#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", HIB"民宅"NOR);
	set("long", 
	HIG"这是一户普通人家，屋里陈设很俭朴，但很整齐，
    墙上有一把柴刀，由于年月久了，刀把上油亮油亮的。一个小伙子
    坐在炕上，低头想着心事.\n"NOR
	);
	set("objects", ([
                __DIR__"npc/lidage" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"xynorth3",
                
	]));
   	setup();
	replace_program(ROOM);
}

