#pragma save_binary
// Room: /u/k/karrimor/temple/corridor6.c

inherit ROOM;

void create()
{
	add_light(this_object(),1);
	set("coor",({1180,4940,35}));
	set("short", "回廊");
	set("long",
"你正走在一条回廊之上,回廊往南北延伸,两端分别连接著大殿及\n"
"后殿。东边是一座花草扶苏的天井,西边是一间上了锁的房间。\n"
);
	set("exits", ([ /* sizeof() == 3 */
     "south" : __DIR__"corridor2",
     "north" : __DIR__"corridor4",
     "east" : __DIR__"inneryard",
]));

	setup();
	replace_program(ROOM);
}
