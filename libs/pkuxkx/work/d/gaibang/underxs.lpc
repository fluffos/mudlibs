#include <room.h>
inherit ROOM;

void create()
{
        set("short", "雪洞");
        set("long", @LONG
这里是雪山半山腰的一个洞，洞外就是积雪，阳光刺眼，空气冰
冷。然而洞内却是一片狼藉，狭窄的通道内堆满了破铜烂铁。暗道到
这里就是尽头了。
LONG
        );

        set("exits", ([
//                        "out" : "/d/lingxiao/xuedi2",
//                        "up" : "/d/lingxiao/xuedi2",
                        "northeast" : __DIR__"xsandao5",
                        "out" : "/d/dalunsi/xuepo",
        ]));

        set("objects",([
                CLASS_D("gaibang") + "/ma-jw" : 1,
         ]));
        setup();
        replace_program(ROOM);
}

