// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/duchang.c

inherit ROOM;

void create()
{
        set("short", "赌场");
        set("long", @LONG
这是长安城中的的赌场。大厅里摆满大大小小的赌桌，只要能说出名的赌
具，这里都有。几个赌徒围在一起，满头大汗的推着牌九，一些人在旁边看着，
多半是输光了又不想走的人。
LONG
        );

        set("exits", ([
                "north" : __DIR__"eastjie1",
        ]));

        set("objects", ([
                __DIR__"npc/duke" : 2,
        ]));

        set("incity",1);
	setup();
}