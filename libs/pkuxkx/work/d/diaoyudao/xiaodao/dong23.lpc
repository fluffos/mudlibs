// Rewrote by zhx@pkuxkx, 2009-09-21
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "east" : __DIR__"dong05",
        "south" : __DIR__"dong24",
    ]));
    setobject();

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
