

inherit ROOM;

void create()
{
	set("short", "新手二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wuliner16",
		"west" : __DIR__"wuliner18",
	]));
	set("objects", (["/HELL1a/GuaiWu5/G/guais" : 5,"/HELL1a/GuaiWu1/G/guais" : 5,
	setup();
}
