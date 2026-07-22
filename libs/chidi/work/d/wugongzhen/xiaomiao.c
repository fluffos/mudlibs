// xiaomiao.c 土地庙
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "土地庙");
        set("long", @LONG
这座庙宇原本是武功镇中的土地庙，不过因为很久没有修缮过，已经
破烂不堪。土地爷的金身也只剩下了半截，供桌只剩下了三条腿，窗框已
经全被下光了，被附近的贫苦百姓拿回家去生火取暖。这里平常是没有人
来的，只有一些游手好闲的地痞流氓之类把这里当做了家。
LONG
        );
        set("exits", ([
                "north" : __DIR__"xijie",
        ]));

        set("objects", ([
                __DIR__"npc/dipi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

