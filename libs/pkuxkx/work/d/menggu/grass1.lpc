// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"草原"NOR);
	set("long", @LONG
一望无际的草原，和天边连成一片。
LONG
	);

	set("exits", ([
		"west" : __DIR__"grass1_w",
		"east" : __DIR__"grass1_e_edge",
		"south" : __DIR__"grass2",
		"north" : __DIR__"grass",
	]));
	set("outdoors", "menggu_e");
	setup();
}
