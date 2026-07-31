// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/southjie1.c

inherit ROOM;

void create()
{
        set("short", "南大街");
        set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。南边是南城门通向城外。北
边则是城中心的钟楼。东边一家店铺门口挂着一很大的“當”字，看来是家当
铺，西边是则是一家老字号的钱庄，可以听到叮叮当当的金银声音。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"dangpu",
                "south"  : __DIR__"southjie2",
                "west"   : __DIR__"qianzhuang",
                "north"  : __DIR__"zhonglou",
        ]));

        set("incity",1);
	setup();
}