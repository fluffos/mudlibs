// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/southjie2.c

inherit ROOM;

void create()
{
        set("short", "南大街");
        set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。南边是南城门通向城外。北
边则是城中心的钟楼。东边一家兵器铺，从里面出来的人个个手里拎个家伙，
那刀光剑影很是让人心惊胆颤。西边的德文堂则不同，出来进去的都是长安城
中的风流才子。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"bingqipu",
                "south"  : __DIR__"southjie3",
                "west"   : __DIR__"dewentang",
                "north"  : __DIR__"southjie1",
        ]));

        set("incity",1);
	setup();
}