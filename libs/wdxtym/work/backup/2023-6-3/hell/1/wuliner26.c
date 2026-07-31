

inherit ROOM;

void create()
{
	set("short", "武林二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wuliner25",
		"east" : __DIR__"wuliner27",
	]));
	set("objects", (["/HELL1/GuaiWu5/G/guais" : 10,"/HELL1/GuaiWu1/G/guais" : 5,]));
	setup();
}
