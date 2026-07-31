
// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("coor",({2300,3780,0}));
	set("short", "茶场");
        set("long",
"这里是绮云镇的茶场，绮云盛产茶叶，因此这里有不少茶工在忙着采茶。\n"
);
        set("exits", ([ /* sizeof() == 1 */
//  "northwest" : __DIR__"eroad3",
  "north" : __DIR__"eroad4.c",
"south" : __DIR__"eroad5.c",
]));

        set("objects", ([
                __DIR__"npc/worker" : 2,
        ]) );
        set("clean_up", 1);
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

