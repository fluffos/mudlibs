#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"后宫门"NOR);
	set("long",
HIC"这里是宁寿全宫的后宫门，由此向北就可以离开宁寿宫。\n"NOR
	);

	set("exits", ([
        "north" : __DIR__"tongdao7",
        "south" : __DIR__"yihexuan",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
