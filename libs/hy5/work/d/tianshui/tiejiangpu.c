// Room: /d/snow/smithy.c

inherit ROOM;

void create()
{
        set("short", "打铁铺子");
        set("long", @LONG
这里是一间打铁铺子，从火炉中冒出的火光将墙壁映得通红，
屋子的角落里堆满了各式铁器的完成品或未完成品，像是锄头、
铁锤、铲子、长剑等，叮叮当当的声音敲得满屋子响。由于靠着
军营，听说周铁匠有时还干点修理兵器和修理铠甲的活。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad2",
]));

        set("objects", ([
                __DIR__"npc/smith": 1 ]) );
        setup();
        replace_program(ROOM);
}
