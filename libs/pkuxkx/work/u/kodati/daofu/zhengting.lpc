// zhengting 正厅
#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "正厅");
    set("long",
@TEXT  这里是整个庄院的正厅。桌明几净，所有家具均为楠木打造。东西两壁挂
着几幅字画，主座身后是一幅泼墨山水。再往里走，就是通往内院的走廊了。
TEXT);

    set("valid_startroom", 1);

    set("exits", ([
        "north" : __DIR__"neixiaodao1",
        "south" : __DIR__"qianyuan",
        "west" : __DIR__"fanting",
        "east" : __DIR__"jingshe",
    ]));

    setup();
}
