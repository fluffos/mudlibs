// by jjyy

inherit ROOM;

void create()
{
	set("short", "荒芜中央");
	set("long", "这里是荒芜之地的中央。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"beijie1",
		"south" : __DIR__"nanjie1",
		"west" : __DIR__"xijie1",
		"east" : __DIR__"dongjie1",
	]));
	set("objects", ([
	]));
	setup();
}

