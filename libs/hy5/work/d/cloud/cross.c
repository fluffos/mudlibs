
// Room: /u/cloud/square.c

inherit ROOM;

void create()
{
        set("coor",({2100,3800,0}));
	set("short", "十字路口");
        set("long",
"绮云镇的两条青石路在这里交叉，路旁栽着棵古槐，有两个汉子合抱那么粗。槐树下有个告\n"
"示，象是官府立的。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad2",
  "north" : __DIR__"nroad2",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

