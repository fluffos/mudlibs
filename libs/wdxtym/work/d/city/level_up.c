// Room: /city/level_up.c

inherit ROOM;

void create()
{
	set("short", "树屋");
	set("long", @LONG
这里是扬州广场大榕树上的树屋，angelus夫妻俩为广大玩家服务，它坐落在广场的大榕树上。
LONG );
	set("no_fight", 1);
	set("exits", ([
		"down" : __DIR__"shiji",
		"east" : __DIR__"guest",
	]));
	set("objects", ([
		__DIR__"npc/angelus": 1,
		__DIR__"npc/jihaolan" : 1,
	]));
	setup();
}

