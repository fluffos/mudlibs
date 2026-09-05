// Room: /u/kiss/quanzhen/zoulang3.c
// Made by: kiss

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"走廊"NOR);
	set("long", @LONG
你走在一条走廊上，走廊两边的柱上雕着精美的花纹,四周一片寂静
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhengting",
"east":__DIR__"lianwuchang",
"south":__DIR__"zhutianbu",
"north":__DIR__"haotianbu"
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
