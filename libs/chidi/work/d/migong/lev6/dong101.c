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
		"north" : __DIR__"dong102",
		"west" : __DIR__"dong100",
                                	]));
         set("objects", ([
               __DIR__"npc/boss" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("bai yuan", environment(me))))
                return notify_fail(HIW"白猿"NOR"一跃拦住你的去路。\n");

        return ::valid_leave(me, dir);
}
