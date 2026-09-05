// Rewrote by zhx@pkuxkx, 2009-02-11
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "east" : __DIR__"shanlu5",
        "south" : __DIR__"dong"+(random(13)+3),
        "west" : __DIR__"dong"+(random(8)+3),
        "north" : __DIR__"dong"+(random(3)+3),
    ]));

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
