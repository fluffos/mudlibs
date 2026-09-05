// woshi 卧室
#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "卧室");
    set("long",
@TEXT    这里便是此间主人的卧室了。
TEXT);
    set("sleep_room",1);

    set("exits", ([
        "south" : __DIR__"neixiaodao2",
        "west" : __DIR__"yaofang",
        "east" : __DIR__"shufang",
    ]));

    setup();
}

void init() {
    add_action("do_sleep", "sleep");
}

int do_sleep() {
    object me = this_player();
    string id = me->query("id");

    if (id != "kodati" && id != "tati") {
        write("跑主人卧室来睡觉，有你这么当客人的么？！\n");
        return 1;
    }

    return 0;
}
