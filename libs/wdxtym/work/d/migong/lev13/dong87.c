#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"熔岩洞"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong7"+(random(6)+1),
		"south" : __DIR__"dong01",
                "west" : __DIR__"dong88",
                "north" : __DIR__"dong6"+(random(5)+1),
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(4)+3),
                "north" : __DIR__"dong8"+(random(2)+7),
	]));
if (random(4)==0)
	set("exits", ([
		"east" : __DIR__"dong01",
                "west" : __DIR__"dong8"+(random(2)+7),
	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
