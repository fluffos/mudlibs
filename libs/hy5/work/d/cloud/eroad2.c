
// Room: /u/cloud/eroad2.c

inherit ROOM;

void create()
{
        set("coor",({2200,3800,0}));
	set("short", "绮云镇街道");
        set("long",
"这里是绮云镇东，通往茶场的路。南边是一家有名的大镖局--振远镖局。北面是绮云张家的\n"
"宅院。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eroad1",
  "north" : __DIR__"park",
  "south" : __DIR__"biaoju",
  "northeast" : __DIR__"eroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

