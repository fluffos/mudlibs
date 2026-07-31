#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", YEL"岩洞出口"NOR);
	set("long", YEL @LONG
    周围都是黄褐色的岩石，感觉上已经在地下很深的地方了,
往上是条狭窄的石道。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong1",
		"west" : __DIR__"dong22",
                "up" : "/d/migong/lev9/dong102",
                "newup" : "/d/migong/12gong/toby1",
                	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
