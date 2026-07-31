// Room: /wizhome/lanzhou/nroad3.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这就是丝绸之路，从古代起这就是中国和西方各国进行经济和文化交流的
一条重要的陆上通道。
你走在一条黄土路上，路的两边种满了泡桐树，这里人很少，偶尔有几个
骑着骆驼的西域商人向南匆匆走去。
LONG
        );
        set("outdoors", "lanzhou");

        set("exits", ([
                "southeast" : __DIR__"nroad2",
                "northwest" : __DIR__"nroad4",
        ]));

        setup();
        replace_program(ROOM);
}

