
// Room: /u/cloud/nwroad3.c

inherit ROOM;

void create()
{
        set("coor",({2050,3900,0}));
	set("short", "中市场");
        set("long",
"这里是绮云镇的中市场，北面是茶楼，南面是杂货铺。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nwroad2",
  "north" : __DIR__"tearoom",
  "south" : __DIR__"zaihuoy",
  "east" : __DIR__"nroad1",
]));
        set("outdoors", "cloud");



        setup();
        replace_program(ROOM);
}

