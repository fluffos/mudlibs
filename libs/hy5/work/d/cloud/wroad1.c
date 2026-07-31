
// Room: /u/cloud/wroad1.c

inherit ROOM;

void create()
{
        set("coor",({2000,3800,0}));
	set("short", "绮云镇街道");
        set("long",
"东边青板石铺的路与向西的碎石小径在这里汇合。西面仿佛是座庄院，似可听到曲乐声，却\n"
"又分辨不清;南面是家私塾。\n"
);
        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"latemoon/entrance",
  //"north" : __DIR__"marry_room",
  "south" : __DIR__"bookstore",
  "east" : __DIR__"wroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

