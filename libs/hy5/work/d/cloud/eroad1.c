
// Room: /u/cloud/eroad1.c

inherit ROOM;

void create()
{
        set("coor",({2150,3800,0}));
	set("short", "绮云镇街道");
        set("long",
"这里是十字路口的东侧，两边房子里都颇为吵闹。北面似乎是家春楼，不时可听到风尘女子\n"
"的卖笑声。南面却是些三教九流的人物在吆三喝五，象是家赌场。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cross",
  "north" : __DIR__"jiyuan",
//  "south" : __DIR__"duchang",
  "east" : __DIR__"eroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

