#include <room.h>
inherit ROOM;
void create()
{
    set("short", HIC "前厅" NOR);
    set("long", @LONG
这里是梅庄的前厅，主要是用来接待来访的客人的。厅中悬着一
幅画，仔细一看，画中所绘的是一个仙人的背面，墨意淋漓，笔力雄健。
画上提款：“丹青生大醉后泼墨”。
,
LONG
    );
    set("exits", ([
         "north" : __DIR__"yuan",
        "south" : __DIR__"luojian",
    ]));
    set("objects",([
    ]));
    setup();
//    replace_program(ROOM);
}

