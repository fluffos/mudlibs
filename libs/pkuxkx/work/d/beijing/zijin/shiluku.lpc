// Room: /d/beijing/zijin/shiluku.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"实录库"NOR);
	set("long",
HIC"这是一栋砖木结构的库房，为避外火，以砖为表，不露木植。
库内楼上楼下贮有大量史书。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"west" : __DIR__"hongbenku",
]));

	setup();
	replace_program(ROOM);
}
