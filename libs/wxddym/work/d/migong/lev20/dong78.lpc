#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"王家的灵墓"NOR);
	set("long", HIM @LONG
这是传说中光神的的灵墓，通路的中央飘浮著一颗颗闪亮
的红水晶。四周的墙壁和天花板上满布著美丽的壁画和精致
的石雕。四周散发著神秘的光芒。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"westnorth" : __DIR__"dong7"+(random(5)+5),
		"eastsouth" : __DIR__"dong7"+(random(5)+4),
		"southdown" : __DIR__"dong7"+(random(4)+1),
		"northup" : __DIR__"dong79",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+5),
		"east" : __DIR__"dong7"+(random(4)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong79",
		"north" : __DIR__"dong7"+(random(4)+4),
	]));
         set("objects", ([
              __DIR__"npc/lev9" : 5,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
