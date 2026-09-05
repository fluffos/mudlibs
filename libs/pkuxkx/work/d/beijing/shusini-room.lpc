// Room: /d/beijing/shusini-room.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"地下密室"NOR);
        set("long",
"这是一间非常宽大的地下室，奇怪的是这里看起来没有任何赌具。骰子，斗鸡都没有。\n只在角落里放着一台奇怪的机器。\n"
        );

        set("no_fight",1);
        set("no_steal",1);
        set("exits", ([                
                "up": __DIR__"dating",
        ]));

        set("objects", ([
                 "/d/gift/jason/bet": 1,
        ]));
        set("max_user",10);
        setup();
}

