// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/lijia.c

inherit ROOM;

void create()
{
        set("short", "李家大院");
        set("long", @LONG
这里便是长安城首富李员外的私宅。迎面是一个假山水池，池上摆着一块
奇形怪状的石头，据说是当年花石纲的遗石。水池的两旁种满了花草。东边是
一棵槐树，郁郁葱葱，遮盖了大半个院子。整个院子里阴阴凉凉的。几个家丁
在收拾着院子。
LONG
        );
        set("exits", ([
                "east"  : __DIR__"neijie7",
                "west"  : __DIR__"ljzhengting",
                "north" : __DIR__"ljzhangfang",
        ]));

        set("objects", ([
                __DIR__"npc/jiading" : 2,
        ]));

        set("incity",1);
	setup();
}
