// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jiangjunfu.c

inherit ROOM;

void create()
{
        set("short", "将军府");
        set("long", @LONG
这里是长安城守城将军的府宅。大门两侧有两头高大的石狮子，还有几名
官兵把守着。东边是一棵槐树，郁郁葱葱，遮盖了大半个院子，整个院子里阴
阴凉凉的。
LONG
        );
        set("exits", ([
                "south" : __DIR__"jjfzht",
                "west"  : __DIR__"jjfxf",
                "north" : __DIR__"westjie2",
        ]));

        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));

        set("incity",1);
	setup();
}
