#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞口");
        set("long", @LONG
你终于到岸了，你精疲力尽水淋淋的爬了上去，原来这是瀑布后面
的一个山洞口，望里走就是山洞了，按照游戏的惯例，这里应该有
秘密，想到这你忍不住都乐出声来了，你昂起头，不顾一切雄赳赳
的向前走去，
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"hole",
            "south" : __DIR__"dongkou",
               ]));
        set("no_clean_up", 0);
        setup();
}


