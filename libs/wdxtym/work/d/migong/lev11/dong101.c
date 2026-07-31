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
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
              __DIR__"npc/boss" : 1,
             "/d/migong/obj/npc1" : random(3),
                ]));
	set("no_clean_up", 0);
	setup();

}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("sha shou", environment(me))))
                return notify_fail(HIR"杀手之王"NOR"阴笑道：“既然你发现了这里，还想活着出去?\n");
       if ( dir == "west" && objectp(present("sha shou", environment(me))))
                return notify_fail(HIR"杀手之王"NOR"阴笑道：“既然你发现了这里，还想活着出去?”\n");

        return ::valid_leave(me, dir);
}

