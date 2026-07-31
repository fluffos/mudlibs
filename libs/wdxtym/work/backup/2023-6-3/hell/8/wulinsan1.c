

inherit ROOM;

void create()
{
	set("short", "四圣三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : "/data/home/q/qiaojia30_1/hell/sc",
		"west" : __DIR__"beijie5",
		"east" : __DIR__"wulinsan2",
	]));
	set("price_build", 1000);
	setup();
}
