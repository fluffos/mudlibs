#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"北大街"NOR);
	set("long", @LONG
你走在一条宽阔的石板大街上，北面是北门大街和玄武大街的十
字路口。东面是一家老字号的药铺，看病买药，长安独此一家。
北面遥遥可见皇城大门。
LONG
	);

	set("exits", ([
 "north" :__DIR__"bdj3",  
 "south" :__DIR__"bdj1",
 "west"  :__DIR__"ylby",
 "east"  :__DIR__"hchyp",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

