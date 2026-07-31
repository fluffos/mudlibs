
// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("coor",({2300,3800,0}));
	set("short", "茶场");
        set("long",
"这里是绮云镇的茶场，绮云盛产茶叶，因此这里有不少茶工在忙着采茶。\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"eroad3",
  "south" : __DIR__"eroad6.c",


]));

        set("objects", ([
                __DIR__"npc/worker" : 3,
        ]) );
        set("clean_up", 1);
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

