
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
		"east" : __DIR__"dong"+(random(20)+1),
		"south" : __DIR__"dong"+(random(15)+1),
                "west" : __DIR__"dong"+(random(10)+1),
                "north" : __DIR__"dong"+(random(5)+1),
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
