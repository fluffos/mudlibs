#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞口");
        set("long", @LONG
你顶着水流奋力向瀑布的入水处游去，水流湍急，冲的你争不开
眼睛，你赶忙屏一口气，把头埋在水里，向前游去
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"hole1",
            "south" : __DIR__"hushui1",
         "west": __DIR__"hushui5",
             ]));
        set("no_clean_up", 0);
        setup();
}


