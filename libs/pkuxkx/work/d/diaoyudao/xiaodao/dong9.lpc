// Rewrote by zhx@pkuxkx, 2009-09-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "south" : __DIR__"dong85",
        "north" : __DIR__"dong92",
    ]));

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
