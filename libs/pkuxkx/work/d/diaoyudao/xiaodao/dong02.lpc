// Rewrote by zhx@pkuxkx, 2009-09-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "east" : __DIR__"dong"+(random(19)+2),
        "south" : __DIR__"shanlu4",
        "west" : __DIR__"dong"+(random(9)+2),
        "north" : __DIR__"dong"+(random(4)+2),
    ]));

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
