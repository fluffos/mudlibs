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
		"west" : __DIR__"dong69",
		"east" : __DIR__"dong69",
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong69",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong69",
		"east" : __DIR__"dong69",
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong69",
	]));
         set("objects", ([
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/lev8" : 3,
              __DIR__"npc/lev5" : 3,
              __DIR__"npc/player" : 3,
              __DIR__"npc/boss1" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
