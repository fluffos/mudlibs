
// Room: /u/cloud/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({2250,3850,0}));
	set("short", "绮云镇街道");
        set("long",
"这里是绮云镇东头，北面是张家，东南方就是茶场。\n"
);
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"rich",
  "southwest" : __DIR__"eroad2",
  "southeast" : __DIR__"eroad4",

]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

