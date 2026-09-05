// Room: /zhx room.c
// ZHX 2009/8/25 

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "陋室");
    set("long", @LONG
这里是旭心修心养性的地方。这里静谧肃穆。
LONG);
    set("no_fight", 1);
    set("no_perform", 1);
    set("no_steal", 1);
    set("no_sleep_room", 1);

    set("exits", ([
        "south" : __DIR__"xiaoyuan",
            ]));
    setup();
}

int do_none()
{
    write("请不要破坏这里静谧的氛围。\n");
    return 1;
}



