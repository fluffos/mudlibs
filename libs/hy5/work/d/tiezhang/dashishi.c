// Room: /u/bobo/tiezhang/dashishi.c

inherit ROOM;

void create()
{
        set("short", "大石室");
        set("long", @LONG
四周石壁上火把在燃烧着，墙角四周放满了大铁箱，打开一看，都是珠宝
黄金。中间架子上供着二件宝兵器，其一宛如一条金龙盘旋着，其二宛如一片
火红的云朵飘浮在空中。
LONG
        );

        set("exits", ([ 
"out" : __DIR__"taijie-2",
]));
        set("objects", ([
        __DIR__"obj/jia2" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);        
}

