#pragma save_binary
// Room: /d/green/path3.c

inherit ROOM;

void create()
{
	set("coor",({65,4900,10}));
	set("short", "三叉路口");
	set("long",
"你来到一条三叉路口,往东看去是另一条更小更窄的黄土路,主要\n"
"道路是南北向的,西边有一栋民宅.\n"
);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/green/path2",
  "south" : "/d/green/path4",
  "west" : "/d/green/house0",
  "east" : "/d/green/path8",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
