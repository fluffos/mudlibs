// Room: /city/nandajie1.c
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
南大街乃是城里的繁华地段，一到晚上，一派灯红酒绿，尤为热闹。笑声、
歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿意马，很想就此停
步享受一番。
LONG );
	set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		//"west"  : __DIR__"lajichang",
		"north" : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
		__DIR__"npc/liumang": 2,
		__DIR__"npc/liumangtou" : 1,
		"/clone/npc/xunbu" : 1,
		"/d/boss/jiangshi": 3,

	]));

	setup();
}

