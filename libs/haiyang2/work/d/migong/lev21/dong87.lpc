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

	set("exits", ([
		"eastdown" : __DIR__"dong88",
            	"westdown" : __DIR__"dong8"+(random(4)+3),
		"southdown" : __DIR__"dong8"+(random(4)+3),
		"northdown" : __DIR__"dong8"+(random(4)+3),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong8"+(random(4)+5),
		"north" : __DIR__"dong8"+(random(4)+5),
	]));
	set("no_clean_up", 0);
         set("objects", ([
              __DIR__"npc/lev8" : 3,
              "/clone/box/gboxm" : random(2),
         ]));
	setup();
	replace_program(ROOM);
}
