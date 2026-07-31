
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "罗刹兵营");
	set("long",
"此处为罗刹征南驻军的入口，东边为军队饮食的地方，在门口的两侧有两位小兵正在值勤。\n"
"南、北两侧为小兵的营帐。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"by3",
  "east" : __DIR__"shanlu5",

]));

        set("objects", ([
               "/kungfu/class/hu/wgb" : 5,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("luosha gui", environment(me))) && 
		dir == "west")
		return notify_fail("一队罗刹兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}                                                                                                                                                                             