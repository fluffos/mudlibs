#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞入口"NOR);
	set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了,左面有条往下的小路。 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong101",
                "down" : "/d/migong/lev6/dong21"
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
