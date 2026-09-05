// Rewrote by zhx@pkuxkx, 2009-09-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "east" : __DIR__"dong"+(random(17)+4),
        "south" : __DIR__"dong"+(random(12)+4),
        "west" : __DIR__"dong"+(random(7)+4),
        "north" : __DIR__"shanlu4",
    ]));

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
