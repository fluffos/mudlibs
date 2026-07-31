
// Room: /u/cloud/nwroad2.c

inherit ROOM;

void create()
{
        set("coor",({2000,3900,0}));
	set("short", "西市场");
        set("long",
"这里是绮云镇的西市场，西边是家棺材铺，南面是家布庄。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"woodboxy",
  "north" : __DIR__"nwroad1",
  "south" : __DIR__"tailory",
  "east" : __DIR__"nwroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

