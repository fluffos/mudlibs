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
             __DIR__"npc/boss1" : 2,
"/d/migong/obj/npc1" : random(3),
                ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("jian mo", environment(me))))
                return notify_fail(HIG"剑魔"NOR"大喝到：“要你来得去不得。\n");
       if ( dir == "west" && objectp(present("jian mo", environment(me))))
                return notify_fail(HIG"剑魔"NOR"大喝到：“要你来得去不得。”\n");

        return ::valid_leave(me, dir);
}
