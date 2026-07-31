//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "内屋");
        set ("long", @LONG
屋子里阴暗但干净，而且并不十分窄小，但只有一桌，一凳，一灯。
更显得四壁箫然，空洞寂寞。也衬得那一盏孤灯更昏黄暗淡。壁上的积尘
未除，屋面上还结着蛛网．
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "out" : __DIR__"bu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shenxiang" : 1,
        ]));
        setup();
}