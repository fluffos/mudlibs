// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIG "终南山" NOR );
    set("long", @LONG
这里就是终南山，它如同一道屏风当在长安南面。由于汉武帝曾
在这里祭祀太乙神，故又称太乙山。
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "southdown":__DIR__"ca24",
       "eastdown":__DIR__"ca26",
]));
    setup();
    replace_program(ROOM);
}
