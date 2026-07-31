// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi17",
		"east" : __DIR__"wulinyi19",
	]));
	//set("objects", ([
	setup();
}
