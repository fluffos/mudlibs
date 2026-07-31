#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
       set("short", RED"熔岩洞"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong78",
		"south" : __DIR__"dong6"+(random(5)+1),
                "west" : __DIR__"dong8",
                "north" : __DIR__"dong5"+(random(5)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
