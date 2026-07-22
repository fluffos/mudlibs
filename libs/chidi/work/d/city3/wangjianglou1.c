//bye enter

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "望江楼");
        set("long",@LONG
这里就是有名的望江楼了，楼外是成都的府南河。河面不
宽，对岸就是一片竹林，林里有口井称做薛涛井。是一带才女
葬身之地。楼上视野辽阔可以远眺锦官城。
LONG
        );

        set("exits", ([
                "north" : __DIR__"funanhe3",
                "up" : __DIR__"wangjianglou2",
                "east" : __DIR__"wanliqiao",
            ]));
        setup();
        replace_program(ROOM);       
}


