
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "钟楼");
    set("long", @LONG
这里是天龙寺的钟楼，一口巨大的铜钟(bell)悬在顶上，只有爬上二楼才
能敲响铜钟。
LONG
       );
    set("item_desc",(["bell":"一口巨大的黄铜钟悬在梁上。\n"
                    ]));
    
    set("exits", ([
                "west" : __DIR__"changlang2",
                "up" : __DIR__"zhonglou2",
                ]));
    set("objects", ([
                __DIR__"npc/shami" : 1,
                     ]) );
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
