
// Room: /d/snow/mstreet2.c

inherit ROOM;

void create()
{
        set("coor",({-50,4770,10}));
	set("short", "宁远城街道");
        set("long",
"你正走在宁远城的大街，往东走不远处是宁远城的中心广场，在你的北边是一间规模不小的\n"
"钱庄，好奇心驱使你想去看看，说不定会有什么好东西拿呢。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bank",
//  "south" : "/d/snow/mstreet1",
  "east" : __DIR__"mstreet1",
  "west" : __DIR__"mstreet3",
]));
        set("objects", ([
              __DIR__"npc/scavenger": 2 ]) );

        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
