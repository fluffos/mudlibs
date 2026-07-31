#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"青龙大街"NOR);
	set("long", @LONG
这里是青龙大街的南段，道路也不再平整宽阔。冷冷清清地令人觉
得不象在都城了。南面是一大片的空地，堆了些木料砖头，大概是
要盖房子。
LONG         
	);

	set("exits", ([ 
 "north":__DIR__"zhq3",
 	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

