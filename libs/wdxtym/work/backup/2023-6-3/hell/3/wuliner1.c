// by jjyy

inherit ROOM;

void create()
{
	set("short", " 风云二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie4",
		"east" : __DIR__"wuliner2",
	]));

	set("objects", (["/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
