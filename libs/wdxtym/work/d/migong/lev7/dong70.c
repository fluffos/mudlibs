#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"钟乳石洞入口"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong69",
		"west" : __DIR__"dong02",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong02",
		"west" : __DIR__"dong69",
                "down" : "/d/migong/lev8/dong01",
                	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
