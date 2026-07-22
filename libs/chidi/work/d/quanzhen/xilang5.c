//xilang5.c 西厢走廊

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
	你走在一条长长的走廊上。
LONG
	);

	set("exits", ([
	     "southwest" : __DIR__"yuanchendian",
             "east" : __DIR__"donglang5",
	]));
	setup();
	replace_program(ROOM);
}
