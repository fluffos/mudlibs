// Write By Yanyang@SJ 2001.9.30
// Room: /d/changan/northjie3.c

inherit ROOM;

void create()
{
        set("short", "北大街");
        set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。南
边则是城中心的钟楼。街的旁边是一条东西延伸的内街，内街很长，里面也有
许多小型的店铺，平常百姓家都住在里面。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"neijie2",
                "south"  : __DIR__"northjie2",
                "west"   : __DIR__"neijie1",
                "north"  : __DIR__"northmen",
        ]));

        set("incity",1);
	setup();
}