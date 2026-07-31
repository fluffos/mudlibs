// by jjyy

inherit ROOM;

void create()
{
	set("short", "东街五号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"dongjie6",
		"west" : __DIR__"dongjie4",
		"north" : __DIR__"wulinsan9",
		"south" : __DIR__"wulinsan10",
	]));
	set("objects", (["/HELL1/GuaiWu5/G/guais" : 10,"/HELL1/GuaiWu1/G/guais" : 5,]));
	setup();
}
