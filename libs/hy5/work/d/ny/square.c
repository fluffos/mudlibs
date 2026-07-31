
// Room: /d/snow/square.c

inherit ROOM;

void create()
{
        set("coor",({0,4750,10}));
       set("my_point","宁远城");
        set("short", "宁远城中心广场");
        set("long",
"这里是宁远城街道的中心广场的空地，地上整齐地铺著大石板。广场中央有一个木头搭的架\n"
"子，经过多年的风吹日晒雨淋，看来非常破旧。四周建筑林立。往西你可以看到一间客栈，\n"
"看来生意似乎很好。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad1",
  "west" : __DIR__"inn",
  "northwest" : __DIR__"mstreet1",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"temple",
]));
        set("outdoors", "ny");

        setup();
}

