

inherit ROOM;

void create()
{
	set("short", "武林二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wuliner19",
		"north" : __DIR__"wuliner21",
	]));
	set("price_build", 1000);
	setup();
}
