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
		"east" : __DIR__"dong7"+(random(6)+1),
		"south" : __DIR__"dong6"+(random(5)+1),
                "west" : __DIR__"dong01",
                "north" : __DIR__"dong88",
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong6"+(random(4)+3),
                "north" : __DIR__"dong8"+(random(2)+7),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(2)+1),
                "west" : __DIR__"dong8"+(random(2)+7),
	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
