// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY+"草原"+NOR);
	set("long", @LONG
一望无际的草原，和天边连成一片。
LONG
	);

	set("exits", ([
		"west" : __DIR__"grass2_w",
		"east" : __DIR__"grass3",
		//"south" : __DIR__"helin_s_link",
		"north" : __DIR__"grass1",
	]));
	set("objects", ([
        	__DIR__"npc/mumin" : 1,
		]));
	set("outdoors", "menggu_e");
	setup();
}
