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
		"east" : __DIR__"dong7"+(random(4)+5),
		"south" : __DIR__"dong11",
                "west" : __DIR__"dong8"+(random(4)+5),
                "north" : __DIR__"dong98",
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong5"+(random(4)+3),
                "north" : __DIR__"dong9"+(random(2)+7),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(2)+1),
                "west" : __DIR__"dong6"+(random(4)+5),
	]));
         
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
