// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie3.c

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。西边是西城门通向城外。东
边则是城中心的钟楼。北面就是长安的驿站，长安城里的居民可以在那儿免费
和外地书信来往。南面则是很有名号的虎威镖局。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"westjie2",
                "south"  : __DIR__"biaoju",
                "west"   : __DIR__"westjie4",
                "north"  : __DIR__"yizhan",
        ]));

        set("incity",1);
	setup();
}