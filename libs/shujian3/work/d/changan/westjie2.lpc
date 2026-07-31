// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie2.c

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。西边是西城门通向城外。东
边则是城中心的钟楼。北面就是长安府的衙门了，因为有它建在这里，所以这
里的治安很好。南面则是守城将军非常气派的府宅。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"westjie1",
                "south"  : __DIR__"jiangjunfu",
                "west"   : __DIR__"westjie3",
                "north"  : __DIR__"yamen",
        ]));

        set("incity",1);
	setup();
}