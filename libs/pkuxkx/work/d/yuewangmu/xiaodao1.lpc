//小道
//by male

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"墓前小道"NOR);
	set("long", @LONG
     这是墓前广场前的一条小道，这里看起来十分清洁,也十分安静,偶尔可以听到
麻雀的叫声.
LONG
	);
        set("outdoors", "yuewangmu");

	set("exits", ([
                "north" : __DIR__"muqian",
                "southwest" : __DIR__"xiaodao5",
                "east" : __DIR__"xiaodao2",

	]));

        set("objects", ([
                __DIR__ + "npc/maque" : 2,
                __DIR__ + "npc/baixing" : 1,
        ]));

	setup();
}

