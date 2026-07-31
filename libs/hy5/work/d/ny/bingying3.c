
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "元师大帐");
	set("long",
"你正站在一间大兵营的入口，几队兵丁镇守在大门的两侧，一阵阵吆喝与刀剑碰撞的\n"
"声音从附近传来，通过大门往东可以望见许多大清铁骑正在操练。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bingying2",

]));

        set("objects", ([
               "/kungfu/class/hu/en1" : 1,
               "/kungfu/class/hu/en2" : 1,
        ]));

	set("outdoors", "ny");
	setup();
//        replace_program(ROOM);
}
