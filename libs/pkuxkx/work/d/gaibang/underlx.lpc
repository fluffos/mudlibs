#include <room.h>
inherit ROOM;

void create()
{
        set("short", "雪洞");
        set("long", @LONG
这里是雪山半山腰的一个洞，洞外就是积雪，阳光刺眼，空气冰冷。

LONG
        );

        set("exits", ([

                       "out" : "/d/lingxiao/xuedi2",
                       "southeast" : __DIR__"xsandao5",

        ]));

        set("objects",([
//                CLASS_D("gaibang") + "/ma-jw" : 1,
         ]));
        setup();
        replace_program(ROOM);
}
