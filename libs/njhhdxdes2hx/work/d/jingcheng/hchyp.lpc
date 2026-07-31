// Room: /d/jingcheng/hchyp.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m回春药铺[2;37;0m");
	set("long", @LONG
这是长安城一家老字号的药铺，这药铺简直太老了，以致于匾额上
的“回”字都快看不出来了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bdj2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yang" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
