
// Room: /u/cloud/shijie1.c

inherit ROOM;

void create()
{
        set("coor",({4050,-1100,0}));
	set("short", "青石板路");
        set("long",
"你正走在一条青石板铺成的羊肠小道上,它坎坷不平地伸进山里。你只能看见古老的石级,一\n"
"级一级朝高处铺去,向远处铺去.....前面的路边上,几个挑夫正在休息。.\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shijie2",
  "southwest" : __DIR__"nroad4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

