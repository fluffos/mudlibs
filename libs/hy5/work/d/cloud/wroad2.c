
// Room: /u/cloud/wroad2.c

inherit ROOM;

void create()
{
        set("coor",({2050,3800,0}));
	set("short", "绮云镇街道");
        set("long",
"这里是绮云镇西，东边就是十字路口。南面的院子里甚是喧闹，象是有很多人的样子。北面\n"
"是杂货铺，不过门不朝这个方向开。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad1",
  "south" : __DIR__"monky",
  "east" : __DIR__"cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

