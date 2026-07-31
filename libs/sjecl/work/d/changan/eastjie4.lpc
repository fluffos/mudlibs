// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie4.c

inherit ROOM;

void create()
{
        set("short", "东大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。东边是东城门通向城外。西
边则是城中心的钟楼。南边是长安城的兵营，门口有官兵在站岗放哨。北面是
一条内街，平常百姓家都住在里面。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"eastmen",
                "south"  : __DIR__"bingying",
                "west"   : __DIR__"eastjie3",
                "north"  : __DIR__"neijie7",
        ]));

        set("incity",1);
	setup();
}