
inherit ROOM;

void create()
{
	set("short", "武林四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie6",
		"east" : __DIR__"wulinsi2",
	]));
	set("price_build", 1000);
	setup();
}
