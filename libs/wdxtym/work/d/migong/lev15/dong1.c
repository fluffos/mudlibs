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
		"north" : __DIR__"dong21",
		"south" : __DIR__"dong2",
                	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(5)+1) : 1,
             __DIR__"npc/lev"+(random(5)+1) : 1,
             __DIR__"npc/lev"+(random(5)+1) : 1,
            __DIR__"npc/lev"+(random(5)+1) : 1,
            __DIR__"npc/lev"+(random(5)+1) : 1,
             "/d/migong/obj/npc2" : random(3)+1,             
                ]));
set("no_npc",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
