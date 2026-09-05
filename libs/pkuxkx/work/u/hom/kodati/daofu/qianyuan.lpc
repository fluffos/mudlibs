// qianyuan 前院
#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "前院");
    set("long",
@TEXT  绕过照壁，这里即是刀府前院。落眼处，广大的院落除一些树木花卉外，
并无太多装饰，显得比较空旷。刀府正厅位于正北，往外则可走出庄院大门。
TEXT);

    set("outdoors", "daofu");

    set("exits", ([
        "north" : __DIR__"zhengting",
        "out" : __DIR__"gate",
    ]));

    setup();
}

