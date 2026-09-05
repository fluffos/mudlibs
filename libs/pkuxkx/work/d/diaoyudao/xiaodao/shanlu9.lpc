// Room: /d/xiaodao/shanlu9.c
// Date: by zhx Tue Sep 22 16:00:47 2009

inherit ROOM;
#include "dong.h"

void create()
{
    setshort();
    setlong();

    set("exits", ([
        "east": __DIR__"dong"+(random(61)+5),
        "west": __DIR__"dong"+(random(3)+5),
        "south": __DIR__"dong"+(random(51)+5),
        "north": __DIR__"shanlu10",
    ]));
    
    setobject();
    set("outdoors", "xiaodao");

//  set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

