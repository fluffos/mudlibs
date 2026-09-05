// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "north" : __DIR__"dong19",
        "south" : __DIR__"dong34",
    ]));
    setobject();

//  set("no_clean_up", 0);
    setup();
    setobject();
    set("outdoors", "xiaodao");
    replace_program(ROOM);
}
