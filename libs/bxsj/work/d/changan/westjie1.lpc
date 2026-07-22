// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie1.c

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。西边是西城门通向城外。东
边则是城中心的钟楼。南边是一家富丽堂皇的珠宝店，出来进去的都是有头有
脸的富商。北边高高耸立的建筑便是长安城的鼓楼。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"zhonglou",
                "south"  : __DIR__"zhubaohang",
                "west"   : __DIR__"westjie2",
                "north"  : __DIR__"gulou",
        ]));

        set("incity",1);
	setup();
}