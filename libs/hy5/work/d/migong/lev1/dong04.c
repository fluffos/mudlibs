
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
	set("short", CYN"石洞"NOR);
	set("long", CYN @LONG
这是一个黑漆漆石洞，周围都是坚硬的石壁。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(17)+4),
		"south" : __DIR__"dong"+(random(12)+4),
                "west" : __DIR__"dong"+(random(7)+4),
                "north" : __DIR__"dong"+(random(2)+4),
	]));
        set("objects", ([
               __DIR__"npc/lev"+(random(9)+1) : 2,
              "/clone/box/gbox" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
