#pragma save_binary
// Room: /u/k/karrimor/temple/corridor1.c

inherit ROOM;

void create()
{
	add_light(this_object(),1);
	set("coor",({1220,4920,35}));
	set("short", "回廊");
	set("long",
"你现在正走在一条回廊上,西北方是一座花木扶苏的天井,穿过西\n"
"边的圆形拱门就可以回到大殿。\n"
);
	set("exits", ([ /* sizeof() == 2 */
     "west" : __DIR__"temple1",
    "north" : __DIR__"corridor7",
]));
        create_door("west","木门","east");
	setup();
//	replace_program(ROOM);
}
