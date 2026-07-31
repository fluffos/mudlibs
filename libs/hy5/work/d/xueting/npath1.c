// Room: /d/snow/npath1.c
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
这是一条黄土小路，往西可以回到雪亭镇的主要街道，北边是
一片草地，草地尽头则是一片树林，往东可以听到淙淙的水声，不
远处可以望见一条山溪。
LONG
        );
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"npath2",
                "west" : __DIR__"street01",
]));
        setup();
        replace_program(ROOM);
}
