// nandajie1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
南大街乃是城里的繁华地段，一到晚上，一派灯红酒绿，尤为热闹。
笑声、歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿意马，
很想就此停步享受一番。北边是一个热闹的广场。东边是一家店铺，墙上
写着一个大大的“当”字，仔细倾听，可以听到压低的讨价还价的声音。
西边则是一片喧嚣，夹杂着“一五一十”的数钱声，原来那是方圆千里之
内最大的一家赌场。
LONG
);
	set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		"west"  : __DIR__"duchang",
		"north" : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
	]));

	setup();
	replace_program(ROOM);
}

