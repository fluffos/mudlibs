
inherit ROOM;

void create()
{
	set("short", "瀚海四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsi6",
		"south" : __DIR__"wulinsi8",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
