
inherit ROOM;

void create()
{
	set("short", "北星二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wuliner24",
		"east" : __DIR__"wuliner26",
	]));
	set("price_build", 1000);
	setup();
}
