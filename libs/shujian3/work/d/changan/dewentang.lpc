// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/dewentang.c

inherit ROOM;

void create()
{
        set("short", "德文堂");
        set("long", @LONG
德文堂乃是一家书局。大堂里摆了一排排的书柜，书架上整整齐齐地放着
一些卷轴，堂内还悬挂着几盆花花草草，红绿相间，疏密有致，令人赏心悦目。
这里不但有风骚文人喜欢的诗词，还有些粗浅的功夫书，供城中居民练来强身
健体。
LONG
        );
        set("exits", ([
                "east" : __DIR__"southjie2",
        ]));

        set("objects", ([
                __DIR__"npc/tangwende" : 1,
        ]));

        set("incity",1);
	setup();
}
