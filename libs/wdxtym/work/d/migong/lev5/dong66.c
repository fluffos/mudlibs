#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞"NOR);
	set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong65",
		"south" : __DIR__"dong03",
    "west" : __DIR__"dong1"+(random(9)+1),
    "east" : __DIR__"dong2"+(random(9)+1),
                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
      
	setup();
	replace_program(ROOM);
}
