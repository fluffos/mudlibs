
// Room: /d/snow/smithy.c

inherit ROOM;

void create()
{
        set("coor",({-100,4800,10}));
	set("short", "打铁铺子");
        set("long",
"这里是一间打铁铺子，从火炉中冒出的火光将墙壁映得通红，屋子的角落里堆满了各式铁器\n"
"的完成品或未完成品，像是锄头、铁锤、铲子、长剑等，叮叮当当的声音敲得满屋子响。\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mstreet4",
]));

        set("objects", ([
                __DIR__"npc/blacksmith": 1 ]) );
        setup();
        replace_program(ROOM);
}
