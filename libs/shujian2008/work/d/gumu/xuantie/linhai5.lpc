// by dubei
// Modify By River@sj 99.5.24
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"树林"NOR);
	set("long", @LONG
这里是一片一望无垠林海，每棵树木都有十来丈高，周围阡陌交错，几十
丈高的大树簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫
也无。你似乎迷失了方向，象没头苍蝇般到处乱闯。
LONG
	);
	set("exits", ([
		"south" :  __DIR__"linhai"+(random(10)+1),
		"west" : __DIR__"linhai6",
                "east" :  __DIR__"linhai"+(random(10)+1),
		"north" : __DIR__"linhai"+(random(10)+1),
	]));

        set("outdoors", "襄阳");
        setup();
}

void reset()
{
	set("exits", ([
		"north" :  __DIR__"linhai"+(random(10)+1),
		"south" :  __DIR__"linhai"+(random(10)+1),
		"west" : __DIR__"linhai6",
		"east" : __DIR__"linhai"+(random(10)+1),
	]));
}
