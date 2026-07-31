// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie1.c

inherit ROOM;

void create()
{
        set("short", "东大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。东边是东城门通向城外。西
边则是城中心的钟楼。南边是一家赌场，对面就是万红楼，沸沸嚷嚷的男喊女
叫只一街所隔，街上人来人往、出来进去，好不热闹！
LONG
        );
	set("outdoors", "长安");
	set("exits", ([
                "east"   : __DIR__"eastjie2",
                "south"  : __DIR__"duchang",
                "west"   : __DIR__"zhonglou",
                "north"  : __DIR__"wanhonglou",
        ]));
	set("objects", ([
		CLASS_D("gaibang/qnqigai") : 1,
	]));
        set("incity",1);
	setup();
}