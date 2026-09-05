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
                        "south" : __DIR__"xsandao3",
                        "northeast" : __DIR__"xsandao1",
        ]));

        setup();
        replace_program(ROOM);
}

