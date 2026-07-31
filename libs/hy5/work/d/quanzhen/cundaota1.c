// cundaota1.c 存道塔一层
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "存道塔一层");
        set("long", @LONG
这里是存道塔的一层，存道塔是当年全真弟子用来存放经书的地
方，塔不高，是用一块一块的大青石砌起来的。塔中的梯子也是用青
石所砌，据说之所以用石头砌塔是为了避免失火，烧毁了全真教的经
书。
LONG
        );
        set("exits", ([
                "south" : __DIR__"guozhendian",
                "westup" : __DIR__"cundaota2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
