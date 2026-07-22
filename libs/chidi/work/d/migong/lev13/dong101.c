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
		"north" : __DIR__"dong102",
		"west" : __DIR__"dong100",
                                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/boss" : 1,
              "/clone/box/gbox" : random(3),
                            ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("huo long", environment(me))))
                return notify_fail(HIR"火龙"NOR"一跃拦住你的去路。\n");
       if ( dir == "west" && objectp(present("huo long", environment(me))))
                return notify_fail(HIR"火龙"NOR"一跃拦住你的去路。\n");

        return ::valid_leave(me, dir);
}
