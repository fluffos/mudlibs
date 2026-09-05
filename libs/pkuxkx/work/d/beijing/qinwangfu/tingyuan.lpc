
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"庭院"NOR);
	set("long", @LONG
这里是一处庭院，虽不奢华，却十分大气。
LONG
	);

	set("exits", ([
        "east" : __DIR__"dating",
        "west" : __DIR__"damen",
	]));
    set("max_contain_items",1);
	setup();
}

