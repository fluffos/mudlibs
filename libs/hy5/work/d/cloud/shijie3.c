
// Room: /u/cloud/shijie3.c

inherit ROOM;

void create()
{
        set("coor",({4100,-1000,0}));
	set("short", "青石板路");
        set("long",
"你正走在一条青石板铺成的羊肠小道上,走进一片青桐林,顿时觉得阴凉许多。而出乎你意料\n"
"的是西边居然有一座竹亭。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shijie4",
  "west" : __DIR__"zhuting",
  "south" : __DIR__"shijie2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

