#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"红本库"NOR);
	set("long",
HIC"这是一栋砖木结构的库房，为避外火，以砖为表，不露木植。
库内楼上楼下贮有大量史书。\n"NOR
	);

	set("exits", ([
        "north" : __DIR__"wenhuamen",
        "east"  : __DIR__"shiluku",
	]));

	setup();
	replace_program(ROOM);
}
