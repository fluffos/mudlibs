
// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("short", "茶场");
        set("long",
"这里是绮云镇的茶场，绮云盛产茶叶，因此这里有不少茶工在忙着采茶。\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad6",
]));

        set("objects", ([
                __DIR__"npc/worker" : 2,
        ]) );
        set("no_clean_up", 0);
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

