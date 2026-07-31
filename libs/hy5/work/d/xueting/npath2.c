// Room: /d/snow/npath2.c
inherit ROOM;
void create()
{
        set("short", "溪边小路");
        set("long", @LONG
这里是一条溪边的小路，从这里可以望见北边的山间一道瀑布
从崖上垂下，穿过山坡上的一片树林，以及不远处的草地，往你的
东南边流过，溪水冲激著溪床的岩石，发出很大的响声，往西沿著
小路可以回到雪亭镇的大街，小路向东南可以通往溪边。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"npath3",
                "west" : __DIR__"npath1",
]));
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
