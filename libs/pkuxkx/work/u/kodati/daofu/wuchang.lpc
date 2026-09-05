// wuchang 武场
#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "武场");
    set("long",
@TEXT  这里是内院一角的一片空地，主人习练武功的地方。
TEXT);

    set("objects",([
        "/d/guiyunzhuang/obj/gujia" : 4,
    ]));

    set("outdoors", "daofu");

    set("no_die", 1);

    set("exits", ([
        "north" : __DIR__"wc_zhuangbei",
        "south" : __DIR__"wc_xiulian",
        "west" : __DIR__"neixiaodao1",
        "east" : __DIR__"wc_jineng",
    ]));

    setup();
}
