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
		"out" : __DIR__"dong39",
                	]));
       set("objects", ([
              __DIR__"npc/boss1" : 1,
              "/clone/box/gbox" : 5,  
             "/d/migong/obj/npc1" : random(3),
                             ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "out" && objectp(present("nie long", environment(me))))
                return notify_fail(BLU"孽龙"NOR"一跃拦住你的去路。\n");

        return ::valid_leave(me, dir);
}
