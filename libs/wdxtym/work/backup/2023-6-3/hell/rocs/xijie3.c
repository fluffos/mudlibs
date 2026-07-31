// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie2",
		"west" : __DIR__"xijie4",
		"south" : __DIR__"wulinyi15",
		"north" : __DIR__"wulinyi16",
	]));
	set("objects", (["/adm/npc/renou3" : 1,
	]));
	setup();
}