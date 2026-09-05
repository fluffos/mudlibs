#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"中左门"NOR);
	set("long",
HIC"从这里向北是后右门，向南是太和殿前的大广场。许多太监和侍
卫从这匆匆而过。\n"NOR
	);

	set("exits", ([
        "north" : __DIR__"xiaodao2",
        "southwest" : __DIR__"guang1"
	]));
	set("objects", ([
		"/d/beijing/npc/shiwei3" : 4,
		"/d/beijing/npc/shiwei4" : 4,
		]) );
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
