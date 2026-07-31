#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"石洞入口"NOR);
	set("long", CYN @LONG
这是一个黑漆漆石洞，周围都是坚硬的石壁。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong47",
		"west" : __DIR__"dong17",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong47",
		"west" : __DIR__"dong17",
                "down" : "/d/migong/lev3/dong02",
                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	setup();
	replace_program(ROOM);
}
