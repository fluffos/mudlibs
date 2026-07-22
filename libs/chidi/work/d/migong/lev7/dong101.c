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
		"north" : __DIR__"dong102",
		"west" : __DIR__"dong100",
                                	]));
       set("objects", ([
              __DIR__"npc/boss" : 3,
                            ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("pantu", environment(me))))
                return notify_fail(BLU"少林叛徒"NOR"说道：“既然被你发现了我们难道还会放你走不成？”\n");
        if ( dir == "west" && objectp(present("pantu", environment(me))))
                return notify_fail(BLU"少林叛徒"NOR"说道：“既然被你发现了我们难道还会放你走不成？”\n");

        return ::valid_leave(me, dir);
}
