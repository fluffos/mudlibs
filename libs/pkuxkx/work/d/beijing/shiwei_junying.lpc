#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"营房"NOR);
        set("long",
HIC"这里是侍卫们饮食起居的地方。有的侍卫在睡觉。你
想睡就赶紧吧。\n"NOR
        );
        set("sleep_room",1);

        set("exits", ([
                "east" : __DIR__"jiaochang",
        ]));

        setup();
        replace_program(ROOM);
}

