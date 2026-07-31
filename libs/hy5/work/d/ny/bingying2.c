
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "大清兵营");
	set("long",
"你正站在一间大兵营的入口，几队兵丁镇守在大门的两侧，一阵阵吆喝与刀剑碰撞的\n"
"声音从附近传来，通过大门往东可以望见许多大清铁骑正在操练。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"droad0",
  "north" : __DIR__"bingying3",

]));

        set("objects", ([
               "/kungfu/class/hu/bing" : 6,
        ]));

	set("outdoors", "ny");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("qing bing", environment(me))) && 
		dir == "north")
		return notify_fail("一队清兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}                                                                                                                                                                             