// Room: shanlu2.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
山路越走越陡，一不小心就会摔倒。山路上满是黄土，山
风一吹，吹得你一个灰头土脸，忍不住连打几个喷嚏。一枝枯
树横躺在山路上，几只乌鸦站立枝头，“呱呱”乱叫。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanmen",
  "south" : __DIR__"shanjiao",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
}

