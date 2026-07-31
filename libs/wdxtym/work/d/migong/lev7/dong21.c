#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"钟乳石洞出口"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下,身后有个朝上
的石洞。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong1",
		"west" : __DIR__"dong22",
                "up" : "/d/migong/lev6/dong102",
                "newup" : "/d/migong/12gong/toby1",
                	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
