// Room: /d/beijing/zijin/pibenchu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"批本处"NOR);
	set("long",
HIC"凡是内阁经手的本章都经批本处进呈给皇帝,皇帝阅批后,再由
批本处交内阁。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"maoqindian",
  	"south" : __DIR__"yuehuamen",
]));

	setup();
	replace_program(ROOM);
}
