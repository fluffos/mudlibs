
// Room: /u/cloud/nroad1.c

inherit ROOM;

void create()
{
        set("coor",({2100,3900,0}));
	set("short", "东市场");
        set("long",
"这里是绮云镇的东市场，北面是药店，东面是兵器店。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nwroad3",
  "north" : __DIR__"drugstore",
  "south" : __DIR__"nroad2",
  "southeast" : __DIR__"nroad5",	
  "east" : __DIR__"weapony",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

