// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "west" : __DIR__"dong21",
        "east" : __DIR__"dong28",
    ]));
//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
