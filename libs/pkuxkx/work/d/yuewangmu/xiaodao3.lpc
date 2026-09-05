//小道
//by male

#include <ansi.h>
inherit ROOM;

void create()
{
       set("short", HIY"亭前小道"NOR);
	set("long", @LONG
  这是风波亭前的一条小道,当年岳飞父子就是通过这条小道去的风波亭
LONG
	);
        set("outdoors", "yuewangmu");

	set("exits", ([
                "west" : __DIR__"xiaodao2",
                "east" : __DIR__"xiaodao4",

	]));

        set("objects", ([
                __DIR__ + "npc/daomuren" : 1,
        ]));

	setup();
}

