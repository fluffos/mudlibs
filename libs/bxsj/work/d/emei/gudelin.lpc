// Room: /d/emei/gudelin.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "古德林" NOR);
	set("long", @LONG
这是一片密密的楠木林，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，据
说有七万株之多，要是不熟悉地形很容易迷路。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
 	 "east" : __FILE__,
	 "west" : __FILE__,
	 "south" : __FILE__,
	 "north" : __DIR__"gudelin2",
]));
	set("no_clean_up", 0);

	setup();
}
