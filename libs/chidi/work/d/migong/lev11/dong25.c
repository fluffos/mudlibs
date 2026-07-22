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
		"east" : __DIR__"dong20",
		"west" : __DIR__"dong26",
                	]));
set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
   	setup();
	replace_program(ROOM);
}
