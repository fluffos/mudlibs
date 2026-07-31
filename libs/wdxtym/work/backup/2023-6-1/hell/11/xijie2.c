// by jjyy

inherit ROOM;

void create()
{
	set("short", "西街二号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie1",
		"west" : __DIR__"xijie3",
	]));
	set("objects", ([
		"/Aboss2/GW1/G/guais" : 5,
	]));
	setup();
}