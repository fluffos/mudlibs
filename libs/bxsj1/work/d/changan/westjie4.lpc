// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie4.c

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。西边是西城门通向城外。东
边则是城中心的钟楼。北边是清真寺，南边则是城隍庙，里面香烟缭绕，善男
信女们进进出出，颇为喧闹。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"westjie3",
                "south"  : __DIR__"chm",
                "west"   : __DIR__"westmen",
                "north"  : __DIR__"qingzhensi",
        ]));

        set("incity",1);
	setup();
}