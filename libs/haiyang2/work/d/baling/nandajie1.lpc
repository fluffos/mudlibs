// baling/nandajie1
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
南大街乃是城里的繁华地段，一到晚上，一派灯红酒绿，尤为热闹。
笑声、歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿意马，
很想就此停步享受一番。北边是一个热闹的广场。东边是一家店铺，墙上
写着一个大大的“当”字，仔细倾听，可以听到压低的讨价还价的声音。
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"east" : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		
		"north" : __DIR__"guangchang",
	]));

	setup();
	replace_program(ROOM);
}

