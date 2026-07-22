#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞"NOR);
	set("long", @LONG
 你越走越深，周围的墙壁似乎有些松软了。 
LONG );
	set("exits", ([
		"east" : __DIR__"dong56",
		"west" : __DIR__"dong57",
                	]));
       set("objects", ([
              "/clone/box/gbox" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
