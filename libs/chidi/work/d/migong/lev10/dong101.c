#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", YEL"岩洞"NOR);
	set("long", YEL @LONG
    周围都是黄褐色的岩石，感觉上已经在地下很深的地方了。 
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
        if ( dir == "north" && objectp(present("mang popo", environment(me))))
                return notify_fail(MAG"盲婆婆"NOR"喝道：“老身在此，不容你放肆?\n");
      

        return ::valid_leave(me, dir);
}
