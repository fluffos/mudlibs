// Room: /city/beidajie1.c
// YZC 1995/12/04 

inherit ROOM;
void create()
{
	set("short", "十里长街");
	set("long", @LONG
十里长街乃是城里的繁华地段，一到晚上，一派灯红酒绿，尤为热
闹。笑声、歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿
意马，很想就此停步享受一番。东边是一家生意兴隆的客栈，来自各地
的人们进进出出，据说也是情人们的幽会地点。西边是一家钱庄，可以
听到叮叮当当的金银声音。
LONG
	);
        set("outdoors", "city");
	set("objects", ([
		CLASS_D("btshan") + "/ouyangke" : 1,
		__DIR__"obj/jiao" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
	set("objects", ([
"/clone/master/master"+(random(24)+1): random(2),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

