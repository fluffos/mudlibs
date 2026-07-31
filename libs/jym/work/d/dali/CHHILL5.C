//Cracked by Kafei
// /d/dali/chhill5.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "茶花山南");
        set("long", @LONG
这儿是茶花山的南面，虽然仍然有大量的茶花盛开着，但显然不如山上的品
种好了，放眼望去皆属凡品。
LONG
        );

        set("exits", ([
                "northup" : __DIR__"chhill3.c",
                "southeast" : __DIR__"shilin6.c",
        ]));

        set("cost", 2);
        set("fengamount", 3 + random(3));
        set("outdoors", "dali");
        setup();
        replace_program(ROOM);
}
