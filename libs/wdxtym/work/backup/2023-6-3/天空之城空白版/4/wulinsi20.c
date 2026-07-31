
inherit ROOM;

void create()
{
	set("short", "武林四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsi19",
		"west" : __DIR__"wulinsi21",
	]));
	set("price_build", 1000);
	setup();
}
