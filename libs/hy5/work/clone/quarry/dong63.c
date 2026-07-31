#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"原始森林"NOR);
	set("long", GRN @LONG
这是一个原始森林，森林中烟雾腾腾，水气弥漫。到处都是各种动物。
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong03",
		"west" : __DIR__"dong64",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
