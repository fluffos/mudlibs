// Room: /city/beidajie1.c

inherit ROOM;
void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人
都往南边走去，那里有一个热闹的广场。东边是一家生意兴隆的客栈。西边是一家钱庄。
LONG
	);
	set("outdoors", "city");
	set("objects", ([
		CLASS_D("ouyang") + "/ouyangke" : 1,
		"/adm/npc/zongshi":1,
		"/d/mirror/npc/office": 1,
		"/d/jjfb1/jnpc/npc2": 1,
		"/d/boss/jiangshi": 3,

		__DIR__"npc/tiaoz" : 1,	
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
		//"up" : __DIR__"liangtian",
	]));

	setup();
}
