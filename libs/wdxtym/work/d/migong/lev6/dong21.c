#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞出口"NOR);
	set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了,中间一条弯弯的
小道往上延伸。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong1",
		"west" : __DIR__"dong22",
                "up" : "/d/migong/lev5/dong102",
                	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
