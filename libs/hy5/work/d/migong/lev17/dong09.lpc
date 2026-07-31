
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"黑之沼泽"NOR);
	set("long", BLU @LONG
   一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你必须小心
谨慎你的每一步. 越往东走沼泽的水就越深
LONG NOR);


	set("exits", ([
		"east" : __DIR__"dong0"+(random(9)+1),
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong10",
                "north" : __DIR__"dong0"+(random(9)+1),
	]));
if (random(2)==0)
	set("exits", ([
                "west" : __DIR__"dong10",
		"east" : __DIR__"dong0"+(random(9)+1),
	]));

         set("objects", ([
              "/d/migong/obj/npc1" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
