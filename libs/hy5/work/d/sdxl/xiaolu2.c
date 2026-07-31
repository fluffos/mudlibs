// xtj 
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "小径"NOR);
    set("long", @LONG
轰轰的山洪之声不绝於耳，这里似乎离瀑布很近了。
LONG
    );

    set("outdoors", "xiangyang");

    set("exits", ([
        "south" : __DIR__"xiaolu1",
        "northwest" : __DIR__"pubu",
    ]));

    setup();
    replace_program(ROOM);
}
