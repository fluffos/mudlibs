#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"西长安街"NOR);
	set("long", @LONG
你走在一条宽阔的石板大街上，东面就快到城中心了，可以看到钟楼
耸立于前。北面静静的是一家书局，来往多是些读书人。南面是一家
钱庄，整天看见客人进进出出，显得生意很兴隆。
LONG
	);

	set("exits", ([
 "west" :__DIR__"xchjie4",
 "east" :__DIR__"tamgch", 
 "north":__DIR__"slshj",
 "south":__DIR__"xjqzh",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

