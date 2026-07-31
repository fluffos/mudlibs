// by jjyy

inherit ROOM;

void create()
{
	set("short", "南昼二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie4",
		"east" : __DIR__"wuliner2",
	]));
	set("objects", ([
		"/d/publicnpc/killplayer" : 5,
	]));
	setup();
}
