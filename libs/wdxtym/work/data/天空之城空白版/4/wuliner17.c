

inherit ROOM;

void create()
{
	set("short", "武林二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wuliner16",
		"west" : __DIR__"wuliner18",
	]));
	set("price_build", 1000);
	setup();
}
