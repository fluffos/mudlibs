// neixiaodao2 内院小道
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
        "north" : __DIR__"woshi",
        "south" : __DIR__"neixiaodao1",
        "west" : __DIR__"xixiangfang",
        "east" : __DIR__"dongxiangfang",
    ]));

    setup();
}
