#include <room.h>
inherit ROOM;

void create()
{
        set("short", "暗道");
        set("long", @LONG
这是丐帮 极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG
        );

        set("exits", ([
                        "southwest" : __DIR__"xsandao5",
                        "northeast" : __DIR__"xsandao3",
        ]));

        setup();
        replace_program(ROOM);
}

