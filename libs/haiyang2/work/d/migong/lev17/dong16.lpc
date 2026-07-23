
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"黑之沼泽"NOR);
	set("long", BLK @LONG
   一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你
必须小心越往东走沼泽的水就越深, 而且你的视线也被雾几乎完全地遮
住了. 这地里你已经无法清楚地看到四周的状况了, 只知道你的脚已经
快深陷於沼泽里了.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong1"+(random(7)+4),
                "north" : __DIR__"dong1"+(random(7)+1),
		"east" : __DIR__"dong1"+(random(7)+1),
                "west" : __DIR__"dong17",
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(5)+4),
                "southwest" : __DIR__"dong1"+(random(5)+3),
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+3),
                "north" : __DIR__"dong1"+(random(5)+4),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
