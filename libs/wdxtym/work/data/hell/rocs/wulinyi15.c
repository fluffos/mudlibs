// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi14",
		"north" : __DIR__"xijie3",
	]));
	//set("objects", ([
	setup();
}
