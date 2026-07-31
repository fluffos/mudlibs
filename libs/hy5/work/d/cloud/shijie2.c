
// Room: /u/cloud/shijie2.c


inherit ROOM;

void create()
{
        set("coor",({4100,-1050,0}));
	set("short", "石阶");
        set("long",
"你正走在一条青石板铺成的羊肠小道上,跨过一条小溪,爬上一座山峰,前面又横着一座山峰,\n"
"真把你给累坏了,需要休息一下了。看着那一级级的石阶,你不由得叹了口气。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shijie3",
  "southwest" : __DIR__"shijie1",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

