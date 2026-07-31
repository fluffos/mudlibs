// Room: /wizhome/lanzhou/nroad1.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这就是丝绸之路，从古代起这就是中国和西方各国进行经济和文化交流的
一条重要的陆上通道。
你走在一条黄土大道上，路的两边种满了泡桐树，人来人往非常繁忙，
不时地有骑着骆驼的西域商人匆匆而过。许多本地人在大道两旁摆了一些
小货摊。这里向南是西北大城--兰州。
LONG
        );
        set("outdoors", "lanzhou");

        set("exits", ([
                "south" : __DIR__"beimen",
                "north" : __DIR__"nroad2",
        ]));

        setup();
        replace_program(ROOM);
}

