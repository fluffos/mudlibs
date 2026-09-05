// Rewrote by zhx, 2009-09-11
#include "dong.h"
inherit ROOM;

void create()
{
    
    setshort();
    setlong();

    set("exits", ([
        "east" : __DIR__"dong"+(random(20)+1),
        "south" : __DIR__"dong"+(random(15)+1),
        "west" : __DIR__"shanlu5",
        "north" : __DIR__"dong"+(random(5)+1),
    ]));
    
    setobject();
    set("outdoors", "xiaodao");
    

//  set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
