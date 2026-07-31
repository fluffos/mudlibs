// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie3",
		"north" : __DIR__"beijie5",
		"east" : __DIR__"wuliner1",
		"west" : __DIR__"wuliner28",
	]));
	set("objects", (["/adm/npc/renou" : 1,
	]));
	setup();
}