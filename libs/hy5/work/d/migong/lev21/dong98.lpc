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
		"southdown" : __DIR__"dong99",
		"northup" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong9"+(random(2)+8),
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"westup" : __DIR__"dong9"+(random(4)+6),
            	"eastdown" : __DIR__"dong99",
	]));

	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev8" : 2,
     __DIR__"npc/lev9" : 5,
     __DIR__"npc/lev7" : 2,
         ]));
	setup();
	replace_program(ROOM);
}
