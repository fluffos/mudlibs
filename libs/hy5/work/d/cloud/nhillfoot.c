
// Room: /u/cloud/dragonhill/nhillfoot.c


inherit ROOM;

void create()
{
        set("coor",({1000,4500,10}));
	set("short", "卧龙岗北坡");
        set("long",
"从这往西北有条路通往雪亭镇，向南爬就是卧龙岗。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"nroad",
  "southup" : __DIR__"hummock",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}
