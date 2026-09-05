// Rewrote by zhx@pkuxkx, 2009-09-21
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "south": __DIR__"shanlu11",
        "east" : __DIR__"dong29",
        "west" : __DIR__"dong05",
    ]));
    setobject();

//  set("no_clean_up", 0);
    setup();
    setobject();
    set("outdoors", "xiaodao");
    replace_program(ROOM);
}
