// Room: /d/chengdu/center.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "城中心");
	set("long", @LONG
这里是成都的城中心，是一个热闹的小广场，铺着青石地面。
LONG
	);
        set("outdoors", "成都");

	set("exits", ([
		"east" : __DIR__"ddajie1",
		"west" : __DIR__"xidajie1",
		"south" : __DIR__"nandajie1",
		"north" : __DIR__"beidajie1",
	]));
	set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));
	set("incity",1);
	setup();
}
