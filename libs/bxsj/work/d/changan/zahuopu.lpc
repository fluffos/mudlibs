// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/zahuopu.c

inherit MISC_ROOM;

void create()
{
        set("short", "杂货铺");
        set("long", @LONG
一间老字号的杂货铺。祖孙三代经营下来，在长安城北一带已经有了一些
小名气。这里无论是油盐酱醋，还是大米白面，老百姓日常生活需要的东西一
样都不少。再加上这里的老掌柜待客如宾，杂货铺的生意看来一天比一天好。
    门前立了个牌子(sign)。
LONG
        );

        set("exits", ([
                "north" : __DIR__"neijie4",
        ]));
        
        set("objects", ([
                __DIR__"npc/zhplaoban" : 1,
        ]));
        
        set("incity",1);
	setup();
}