// Rewrote by zhx@pkuxkx, 2009-09-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "east" : __DIR__"shanlu8",
        "south" : __DIR__"dong"+(random(11)+5),
        "west" : __DIR__"dong"+(random(6)+5),
        "north" : __DIR__"dong"+(random(1)+5),
    ]));

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
