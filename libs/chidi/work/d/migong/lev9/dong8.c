#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"钟乳石洞"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下。 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong77",
		"north" : __DIR__"dong84",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
