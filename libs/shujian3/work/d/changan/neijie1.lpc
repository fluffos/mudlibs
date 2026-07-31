// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie1.c

inherit ROOM;

void create()
{
        set("short", "内街");
        set("long", @LONG
这是是长安城的居民区，住的都是平常百姓，所以和那些大街比起来，这
里就不那么整洁了。店铺也都是小小门面，比邻而立，但见人来人往、川流不
息，依然一片繁华的景象。南面是一家小酒馆。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"northjie3",
                "south"  : __DIR__"jiuguan",
                "west"   : __DIR__"shiji",
                "north"  : __DIR__"minju3",
        ]));

        set("incity",1);
	setup();
}