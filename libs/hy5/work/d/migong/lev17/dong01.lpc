
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
		"east" : __DIR__"dong02",
                "west" : "/d/migong/lev16/dong20",
	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev1" : random(3),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(3)+1),
                "west" : "/d/migong/lev16/dong20",
		"south" : __DIR__"dong02",
                "north" : __DIR__"dong0"+(random(3)+1),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
