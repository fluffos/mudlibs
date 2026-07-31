
// Room: /d/snow/sroad1.c

inherit ROOM;

void create()
{
        set("coor",({0,4700,10}));
	set("short", "宁远城街道");
        set("long",
"这是宁远城的街道，往北是一个热闹的广场，南边是条小路通往黄土坡，东边则有一条小径\n"
"沿著山腰通往山上，往西是一条比较窄的街道，参差不齐的瓦屋之间传来几声犬吠。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hockshop",
  "north" : __DIR__"square",
  "south" : __DIR__"nroad3",
//  "south" : "/d/snow/tao",
  "east" : __DIR__"machang",
]));
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
