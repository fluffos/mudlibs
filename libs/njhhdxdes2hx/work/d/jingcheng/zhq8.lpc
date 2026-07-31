#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"朱雀大街"NOR);
	set("long", @LONG
  这里是朱雀大街的东段。往西走几步是朱雀大街和白虎
大街的十字路口。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq7",
 "east" :__DIR__"zhq9",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

