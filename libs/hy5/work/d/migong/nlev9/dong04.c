
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
		set("short", WHT"钟乳石洞"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(17)+4),
		"south" : __DIR__"dong"+(random(12)+4),
                "west" : __DIR__"dong"+(random(7)+4),
                "north" : __DIR__"dong"+(random(2)+4),
	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
