#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"钟乳石洞"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong11",
		"south" : __DIR__"dong98",
                "west" : __DIR__"dong7"+(random(4)+5),
                "north" : __DIR__"dong8"+(random(8)+1),
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(3)+7),
                "north" : __DIR__"dong3"+(random(6)+3),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(2)+1),
                "west" : __DIR__"dong5"+(random(4)+5),
	]));
         set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
