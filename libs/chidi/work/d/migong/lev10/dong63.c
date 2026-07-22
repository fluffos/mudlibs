#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{	
        set("short", YEL"岩洞"NOR);
	set("long", YEL @LONG
    周围都是黄褐色的岩石，感觉上已经在地下很深的地方了。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong03",
		"west" : __DIR__"dong64",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
