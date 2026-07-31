
inherit ROOM;

void create()
{
	set("short", "瀚海四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsi17",
		"west" : __DIR__"wulinsi19",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
