
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
		"south" : __DIR__"dong02",
                "north" : __DIR__"dong0"+(random(3)+1),
		"west" : __DIR__"dong02",
                "up" : "/d/migong/lev19/dong21",
	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev4" : random(3),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(3)+1),
                "up" : "/d/migong/lev19/dong21",
	]));
if (random(2)==0)
	set("exits", ([
		"up" : "/d/migong/lev19/dong21",
                "north" : __DIR__"dong0"+(random(3)+1),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
