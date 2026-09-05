// Rewrote by zhx@pkuxkx, 2009-09-12
#include "dong.h"
inherit ROOM;

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "south" : __DIR__"dong93",
        "north" : __DIR__"dong99", //出口
    ]));

//  set("no_clean_up", 0);
    setobject();
    set("outdoors", "xiaodao");
    setup();
    replace_program(ROOM);
}
