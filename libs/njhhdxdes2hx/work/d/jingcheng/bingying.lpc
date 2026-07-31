#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"东大营"NOR);
	set("long", @LONG
这里是兵营，到处都是官兵走来走去，有的在武将的指挥下列队操
练，有的独自在练功，有的坐着、躺着正在休息。大柳树下树阴里
坐着主帅，不动声色地寻视着四周。
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"dchjie4", 
 
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

