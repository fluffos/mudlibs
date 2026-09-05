// Rewrote by zhx@pkuxkx, 2009-09-21
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "north" : __DIR__"dong88",
        "south" : __DIR__"dong89",
    ]));

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
