#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"钟乳石洞入口"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong79",
		"west" : __DIR__"dong13",
		"north" : __DIR__"dong6"+(random(9)+1),
		"south" : __DIR__"dong7"+(random(9)+1),
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong13",
		"west" : __DIR__"dong79",
                "down" : "/d/migong/lev10/dong03",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
