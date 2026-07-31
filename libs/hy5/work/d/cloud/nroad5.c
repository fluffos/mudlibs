
// Room: /u/cloud/nroad1.c

inherit ROOM;

void create()
{
        set("short", "东市场广场");
        set("long",
"这里是绮云镇的东市场广场。广场上面有不少人。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"nroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

