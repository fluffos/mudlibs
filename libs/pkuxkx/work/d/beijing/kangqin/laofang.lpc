// Room: /d/beijing/kangqin/laofang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"牢房"NOR);
	set("long",
MAG"这是一间牢房。铁门极厚，门上的小窗装着鸭子儿粗细
的铁条，显然是怕犯人冲出来。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"xiaotang",
]));

	setup();
	replace_program(ROOM);
}
