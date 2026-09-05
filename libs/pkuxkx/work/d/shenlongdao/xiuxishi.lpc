
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "休息室");
        set("long", @LONG
这里是神龙教弟子起居的地方。靠墙一溜摆着几张木床，床
上铺的是棉被。使人一看就想睡觉。
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                  "east" : __DIR__"xiaoting",
        ]));
        
    set("no_fight",1);
    set("no_steal",1);
        setup();
        replace_program(ROOM);
}
