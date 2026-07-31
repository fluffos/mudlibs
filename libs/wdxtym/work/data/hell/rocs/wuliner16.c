

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wuliner15",
		"west" : __DIR__"wuliner17",
	]));
	set("objects", ([
	setup();
}
