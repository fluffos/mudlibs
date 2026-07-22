// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie3.c

inherit ROOM;

void create()
{
        set("short", "东大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。东边是东城门通向城外。西
边则是城中心的钟楼。南边是一家花店，门口摆着很多五彩缤纷的花篮，北边
是一家水果店。走到这里你便可闻到一种幽香，但根本分不清是果香还是花香。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"eastjie4",
                "south"  : __DIR__"huadian",
                "west"   : __DIR__"eastjie2",
                "north"  : __DIR__"shuiguodian",
        ]));

        set("incity",1);
	setup();
}