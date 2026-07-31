

inherit ROOM;

void create()
{
	set("short", "武林三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan8",
		"south" : __DIR__"dongjie5",
	]));
	set("price_build", 1000);
	setup();
}
