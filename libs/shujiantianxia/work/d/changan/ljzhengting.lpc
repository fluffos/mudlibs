// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/ljzhengting.c

inherit ROOM;

void create()
{
        set("short", "正厅");
        set("long", @LONG
这里是李员外家的的正厅，正厅里各种古玩琳琅满目，商周青铜、汉瓦当、
唐三彩……，应有尽有，只要拥有一件，就够你吃一辈子了。名人的字画也挂
得满墙都是，厅中正中一把太师椅，李员外平时就坐在那里。
LONG
        );
        set("exits", ([
                "east"  : __DIR__"lijia",
                "west"  : __DIR__"ljwoshi",
                "north" : __DIR__"ljyanting",
        ]));

        set("objects", ([
                __DIR__"npc/liyuanwai" : 1,
        ]));

        set("incity",1);
	setup();
}
