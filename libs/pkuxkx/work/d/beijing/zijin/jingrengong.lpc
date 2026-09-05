// Room: /d/beijing/zijin/jingrengong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"景仁宫"NOR);
	set("long",
HIC"东六宫之一，这是明清两代后妃们居住的地方。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"west" : __DIR__"tongdao4",
  	"south" : __DIR__"chengsudian",
  	"east" : __DIR__"gzxd8",
]));

	setup();
	replace_program(ROOM);
}
