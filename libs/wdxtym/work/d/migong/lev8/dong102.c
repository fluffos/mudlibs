#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{      
        set("short", WHT"钟乳石洞入口"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下,石壁上有个
向下延伸的石洞。 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong101",
                "down" : "/d/migong/lev9/dong21"
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
