#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{      
      set("short", RED"熔岩洞入口"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着,一条红土形成的小道直插入地底。 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong101",
                "down" : "/d/migong/lev14/dong21"
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
