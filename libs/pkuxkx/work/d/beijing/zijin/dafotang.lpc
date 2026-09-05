// Room: /d/beijing/zijin/dafotang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"大佛堂"NOR);
	set("long",
HIC"这是一间佛堂，比一般人家的佛堂要大的多。正中一尊佛像，前
面有只香案，上面点着几柱香。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"south" : __DIR__"cininggong",
]));

	setup();
	replace_program(ROOM);
}
