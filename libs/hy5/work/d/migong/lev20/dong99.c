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
set("no_npc",1);
	set("exits", ([
		"south" : __DIR__"dong100",
		"north" : __DIR__"dong9"+(random(4)+6),
		"east" : __DIR__"dong9"+(random(4)+6),
		"west" : __DIR__"dong9"+(random(4)+6),
	]));

if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong9"+(random(4)+6),
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(4)+6),
		"north" : __DIR__"dong100",
	]));

	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev8" : 8,
     __DIR__"npc/lev6" : 3,
     __DIR__"npc/lev7" : 3,
         ]));
	setup();
	replace_program(ROOM);
}
