#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"朱雀大街"NOR);
	set("long", @LONG
这里是朱雀大街的中段。北面是国子监，可以听到朗朗书声。西面是
朱雀大街和南大街的十字路口，那里正是京城的繁华所在。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"ndj3",
 "east" :__DIR__"zhq6",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

