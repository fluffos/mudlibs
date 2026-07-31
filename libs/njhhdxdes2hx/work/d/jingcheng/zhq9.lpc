#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"朱雀大街"NOR);
	set("long", @LONG
  这里是朱雀大街东段的尽头了，东面是高高的城墙，北面
有一家粮店，好象生意很兴隆的样子。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq8", 
 "north" :__DIR__"fliang",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

