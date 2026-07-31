// xtj 
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "小径"NOR);
    set("long", @LONG
这是一条隐约可变的小路，隐隐听到轰轰之声，不绝於耳，越往北走
声音越响，显是极大的水声。
LONG
    );

    set("outdoors", "xiangyang");

    set("exits", ([
        "southdown" : __DIR__"linhai14",
        "north" : __DIR__"xiaolu2",
    ]));

    setup();
    replace_program(ROOM);
}
