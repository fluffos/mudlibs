// Room: jguan4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "机关");
	set("long", @LONG
这是一间什麽也没有的小石洞，在里走越来越恐怖了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  	"east":__DIR__"jguan"+random(7),
  	"south" : __DIR__"jguan"+random(5),
        "west" : __DIR__"jguan5",
	"north":__DIR__"jguan"+random(1),
]));
	set("no_clean_up", 0);
  set("no_task",1);
	setup();
	replace_program(ROOM);
}
