// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"草原"NOR);
	set("long", @LONG
一望无际的草原，和天边连成一片。
LONG
	);

	set("exits", ([
		"west" : __DIR__"grass2",
		"east" : __DIR__"hill",
		//"south" : __DIR__"helin_s_link",
		"north" : __DIR__"grass1_e_edge",
	]));
	set("outdoors", "menggu_e");
	setup();
}
