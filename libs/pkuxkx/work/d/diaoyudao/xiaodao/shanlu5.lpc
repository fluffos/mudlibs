// Room: /d/xiaodao/shanlu5.c
// Date: by zhx Tue Sep 22 16:00:47 2009

inherit ROOM;
#include "dong.h"

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "north" : __DIR__"shanlu6",
        "east" : __DIR__"dong"+(random(21)+5),
        "west": __DIR__"dong"+(random(41)+5),
        "south": __DIR__"dong"+(random(61)+5),
    ]));
    
    setobject();
    set("outdoors", "xiaodao");
//  set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

