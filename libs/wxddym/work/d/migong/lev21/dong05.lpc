
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"混沌的迷宫"NOR);
	set("long", RED @LONG
这里是混沌的迷宫,似乎是用来避难的地方。然而地
上到处是一堆堆的骨骸与乾掉的血迹。更让人觉得气氛
显得十分的诡异。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+4),
                "west" : __DIR__"dong0"+(random(4)+3),
		"south" : __DIR__"dong0"+(random(4)+3),
                "north" : __DIR__"dong0"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"westeast" : __DIR__"dong0"+(random(4)+4),
		"eastsouth" : __DIR__"dong0"+(random(4)+3),
                "northwest" : __DIR__"dong0"+(random(4)+3),
                "southnorth" : __DIR__"dong0"+(random(4)+3),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(4)+3),
                "north" : __DIR__"dong0"+(random(4)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+3),
                "west" : __DIR__"dong0"+(random(4)+4),
	]));

         set("objects", ([
              __DIR__"npc/lev1" : random(6),
              __DIR__"npc/lev2" : random(6),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
