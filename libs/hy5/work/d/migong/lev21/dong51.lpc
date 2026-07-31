
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"诱惑的宫殿"NOR);
	set("long",RED @LONG
本来这里是一座城市，因为当时的一场灾难把这座城
市的人都给毁灭了。你突然发现，周围的墙壁是用纯金
砌成的。一种无比的诱惑使你继续前进。 
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong52",
		"east" : __DIR__"dong14",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+4),
		"north" : __DIR__"dong1"+(random(3)+4),
		"west" : __DIR__"dong17",
                "east" : __DIR__"dong52",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong52",
		"west" : __DIR__"dong18",
	]));

        set("objects", ([
              __DIR__"npc/lev2" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

