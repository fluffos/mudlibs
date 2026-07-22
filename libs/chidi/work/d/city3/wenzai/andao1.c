//bye enter

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是温家下面一条很隐秘的暗道，也不知道是谁修建的。 
LONG
	);

	set("exits", ([
			"north" : __DIR__"andao2",
                        "up" : __DIR__"xiaoting",
	]));

	setup();
	replace_program(ROOM);
}



