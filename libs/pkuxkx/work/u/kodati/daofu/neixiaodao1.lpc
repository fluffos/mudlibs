// neixiaodao1 内院小道
#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "内院小道");

    set("long",
@TEXT  这是一条青石铺就的露天小道，连接内院各处。
TEXT);

    set("outdoors", "daofu");

    set("exits", ([
        "north" : __DIR__"neixiaodao2",
        "south" : __DIR__"zhengting",
        "west" : __DIR__"putaojia",
        "east" : __DIR__"wuchang",
    ]));

    setup();
}
