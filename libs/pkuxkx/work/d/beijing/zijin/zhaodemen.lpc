#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"昭德门"NOR);
	set("long",
HIC"从这里向北是太和殿，向南是九孔白玉桥。\n"NOR
	);

	set("exits", ([
        "north" : __DIR__"zuoyimen",
        "southwest" : __DIR__"guang2",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
