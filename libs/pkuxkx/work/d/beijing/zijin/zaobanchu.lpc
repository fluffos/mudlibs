#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"造办处"NOR);
	set("long",
HIC"这里是内务府的造办处，专门负责制作各种工艺美术品。\n"NOR
	);

	set("exits", ([
	           "south" : __DIR__"gzxd1",
                      "west" : __DIR__"cininghuayuan",
	]));

	setup();
	replace_program(ROOM);
}
