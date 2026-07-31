
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"黑之沼泽"NOR);
	set("long", BLK @LONG
   一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你必须小心
谨慎你的每一步. 越往东走沼泽的水就越深。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);


	set("exits", ([
		"east" : __DIR__"dong05",
		"west" : __DIR__"dong07",
		"south" : __DIR__"dong0"+(random(4)+4),
                "west" : __DIR__"dong06",
                "north" : __DIR__"dong0"+(random(4)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"westeast" : __DIR__"dong0"+(random(4)+4),
		"eastsouth" : __DIR__"dong0"+(random(4)+4),
                "northwest" : __DIR__"dong07",
                "southnorth" : __DIR__"dong0"+(random(4)+4),
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
