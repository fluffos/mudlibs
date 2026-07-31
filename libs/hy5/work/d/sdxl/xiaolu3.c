// xtj 
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "小径"NOR);
    set("long", @LONG
这里是瀑布西面的一条小径，齐膝的野草几乎把路给掩盖了。
LONG
    );

    set("outdoors", "xiangyang");

    set("exits", ([
        "east" : __DIR__"pubu",
        "northwest" : __DIR__"dongkou",
    ]));

    setup();
    replace_program(ROOM);
}
