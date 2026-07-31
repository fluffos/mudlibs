// Room: /d/changcheng/FengHuoTai2-2.c
// Date: inca 98/08/30

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",HIY "烽火台");
        set("long",WHT @LONG
这里是烽火台的二楼，站在这里你可以看的很远。肃边的将士们就是
长年守卫在这里，防止匈奴的进攻，保卫边疆的安全。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("objects", ([
                 "/d/changcheng/npc/guanbing" : 2,
        ]));

        set("exits", ([
                "down"    :__DIR__"FengHuoTai2-1",
        ]));

        setup();
        replace_program(ROOM);
}
