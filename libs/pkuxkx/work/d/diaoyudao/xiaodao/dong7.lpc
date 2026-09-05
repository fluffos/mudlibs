// Rewrote by zhx@pkuxkx, 2009-09-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "south" : __DIR__"dong69",
        "north" : __DIR__"dong76",
    ]));

//  set("no_clean_up", 0);
    setup();
    setobject();
    set("outdoors", "xiaodao");
    replace_program(ROOM);
}
