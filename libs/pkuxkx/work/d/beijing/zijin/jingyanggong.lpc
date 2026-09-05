// Room: /d/beijing/zijin/jingyanggong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"景阳宫"NOR);
	set("long",
HIC"东六宫之一,这是明清两代后妃们居住的地方。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"yushufang",
  	"west" : __DIR__"gzxd10",
]));

	setup();
	replace_program(ROOM);
}
