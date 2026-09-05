// Room: grass.c 草原
// created by Zine 30 Aug 2010

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
一望无际的草原，和天边连成一片。北面是一片蒙古包。
LONG
	);

	set("exits", ([
		"west" : __DIR__"grass_w",
		"east" : __DIR__"grass_e_edge",
		"south" : __DIR__"grass1",
		"north" : __DIR__"menggubaoexit",
	]));
	set("outdoors", "menggu_e");
	setup();
}
