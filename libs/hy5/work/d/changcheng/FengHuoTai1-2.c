// Room: /d/changcheng/FengHuoTai1-2.c
// Date: inca 98/08/30

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", HIY "烽火台");
        set("long",WHT  @LONG
这里是烽火台的二楼，站在这里你可以看的很远。肃边的将士们就是
长年守卫在这里，防止匈奴的进攻，保卫边疆的安全。从这里向东你隐隐
约约可以看到长城上著名的居庸关。
LONG
NOR       );

        set("outdoors", "changcheng");

        set("objects", ([
                 "/d/changcheng/npc/guanbing" : 2,
        ]));

        set("exits", ([
                "down"    :__DIR__"FengHuoTai1-1",
        ]));

        setup();
        replace_program(ROOM);
}
