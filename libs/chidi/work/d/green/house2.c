#pragma save_binary
// Room: /d/green/house2.c

inherit ROOM;

void create()
{
	set("coor",({75,4910,10}));
	set("short", "民宅");
	set("long",
"这是一间简陋的民宅,屋顶隐约还可以看到一些破洞.墙角堆著些\n"
"柴火,墙壁上还可以看到烟熏的痕迹.除了一些简陋的家具外屋内\n"
"空空荡荡的.\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/green/field0",
]));
	set("no_clean_up", 0);
	set("objects", ([
		"/d/green/npc/oldman" :1,
		"/d/green/npc/oldwoman" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
