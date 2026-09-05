// Rewrote by zhx@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "east" : __DIR__"dong63",
        "west" : __DIR__"dong15",
        "south"  : __DIR__"shanlu8",
    ]));
    setobject();

//  set("no_clean_up", 0);  
//    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
