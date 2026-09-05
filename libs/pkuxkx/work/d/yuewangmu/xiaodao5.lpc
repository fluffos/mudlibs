//小道
//by male

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"墓前小道"NOR);
	set("long", @LONG
   这是一条小道,同向岳王坟,一些忧国之士常到附近缅怀岳王爷.
LONG
	);
        set("outdoors", "yuewangmu");

	set("exits", ([
                "south" : __DIR__"wangyouting",
                "northeast" : __DIR__"xiaodao1",
                "west" : __DIR__"xiaodao6",

	]));

        set("objects", ([
                __DIR__ + "npc/baixing" : 1,
        ]));

	setup();
}

