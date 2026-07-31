// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinyi3",
		"south" : __DIR__"wulinyi5",
	]));
	//set("objects", ([
	setup();
}
