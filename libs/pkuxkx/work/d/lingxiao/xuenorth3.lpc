// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
    set("short", "小酒馆");
    set("long", @LONG
方圆数百里内就此一家酒馆。布置简易，顾客多是雪山派的弟子。
LONG);

    set("exits", ([
        "south" : __DIR__"xuejie3",
    ]));

    set("objects", ([
        __DIR__"npc/xiaoer2" : 1,
    ]));

    setup();
    replace_program(ROOM);
}
