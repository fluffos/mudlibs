
// Room: /u/cloud/nroad2.c

inherit ROOM;

void create()
{
        set("coor",({2100,3850,0}));
	set("short", "南市场");
        set("long",
"这里是绮云镇的南市场，西面是杂货铺，向东可看到怡红院的二楼。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zaihuoy",
  "north" : __DIR__"nroad1",
  "south" : __DIR__"cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

