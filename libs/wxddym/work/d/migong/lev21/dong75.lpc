#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"虚神的洞窟"NOR);
	set("long", HIB @LONG
这洞穴像是一直延申到地底去.而风从地底不停地吹
上来. 一些奇奇怪怪的图形画满了整个洞穴,除此之外,
地上的足迹也是零零乱乱的.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(3)==0)
	set("exits", ([
		"westdown" : __DIR__"dong76",
		"eastdown" : __DIR__"dong7"+(random(4)+3),
	]));
	set("exits", ([
		"east" : __DIR__"dong76",
		"west" : __DIR__"dong7"+(random(4)+3),
		"south" : __DIR__"dong7"+(random(4)+3),
		"north" : __DIR__"dong7"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"southdown" : __DIR__"dong7"+(random(4)+3),
		"northdown" : __DIR__"dong76",
	]));
         set("objects", ([
              __DIR__"npc/lev5" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
