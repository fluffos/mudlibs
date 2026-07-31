

inherit ROOM;

void create()
{
	set("short", "南昼三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsan4",
		"south" : __DIR__"wulinsan6",
	]));
	set("objects", ([
		"/d/publicnpc/killplayers" : 5,
	]));
	setup();
}
