#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"十字路口"NOR);
	set("long", @LONG
这里是白虎大街和朱雀大街的十字路口。这附近的地方是长安城
有名的销金磨光之所。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq6",
 "east" :__DIR__"zhq8", 
 "north" :__DIR__"baih5",
 "south" :__DIR__"baih6",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

