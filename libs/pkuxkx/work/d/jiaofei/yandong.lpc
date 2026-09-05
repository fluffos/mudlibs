//Create by jason@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "岩洞");
        set("long", @LONG
这个岩洞内部足足有百尺之大，光线十分昏暗。有一个出口通向外面。
LONG    );
        set("exits", ([ 
        "out": __DIR__"shidi"
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
        set("objects",([
            __DIR__"obj/yingtengjia":(random(5)+1),
        ]));
        setup();
        replace_program(ROOM);
}