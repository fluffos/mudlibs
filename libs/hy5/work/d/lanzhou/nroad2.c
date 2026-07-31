// Room: /wizhome/lanzhou/nroad2.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这就是丝绸之路，从古代起这就是中国和西方各国进行经济和文化交流的
一条重要的陆上通道。
你走在一条黄土路上，路的两边种满了泡桐树，这里人不是很多，只有一
些有骑着骆驼的西域商人向南匆匆走过。偶尔有两个本地人在大道旁摆了
个小摊。这里向南隐隐约约可以看到兰州城。
LONG
        );
        set("outdoors", "lanzhou");

        set("exits", ([
                "north"     : "/d/xibei/jincheng_guan",
                "south"     : __DIR__"nroad1",
                "northwest" : __DIR__"nroad3",
        ]));

        setup();
        replace_program(ROOM);
}

