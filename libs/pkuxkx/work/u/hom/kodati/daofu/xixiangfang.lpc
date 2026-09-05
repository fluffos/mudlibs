// xixiangfang 西厢房
#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "西厢房");
    set("long",

@TEXT    这是一间客房，若有客人来访留宿，即可住在此处。房间内诸物齐备，纤
尘不染，可见时常有人打扫。
TEXT);

    set("sleep_room",1);
    set("no_fight",1);
    set("exits", ([
        "east" : __DIR__"neixiaodao2",
    ]));

    setup();
}
