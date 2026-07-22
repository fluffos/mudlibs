// Write By Yanyang@SJ 2001.9.30
// Room: /d/changan/chengyidian.c

inherit ROOM;

void create()
{
        set("short", "成衣店");
        set("long", @LONG
这里是一家成衣铺，是长安城内的居民常到之处，现在也挤得凄凄惨惨。
因为这里卖的衣服都正合人们的心意。店主是个很靓丽的年轻女子，现在正和
几个唧唧喳喳的姑娘围着一件旗袍议论着什么。
LONG
        );

        set("item_desc", ([
                "paizi" : "只供成衣，恕不定做\n",
        ]));

        set("exits", ([
                "east" : __DIR__"northjie2",
        ]));

        set("objects", ([
                __DIR__"npc/hou" : 1,
        ]));
        set("incity",1);
        setup();
}