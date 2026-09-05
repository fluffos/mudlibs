
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "钟楼二层");
    set("long", @LONG
这里是天龙寺的钟楼二楼，一口巨钟(bell)就在你面前，你可以敲响(knock)
它。
LONG
       );
    set("item_desc",(["bell":"一口巨大的黄铜钟悬在梁上。\n"]));
    
    set("exits", ([
                "down" : __DIR__"zhonglou",
                
                ]));
    set("objects", ([
                __DIR__"obj/bell" : 1,
                     ]) );
    set("no_clean_up", 0);
    setup();
}
