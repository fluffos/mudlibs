// Room: /d/beijing/zijin/houdian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"后殿"NOR);
	set("long",
HIC"从这里往北去是寿安宫，南边是寿康宫。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shouangong",
  "south" : __DIR__"shoukanggong",
]));

	setup();
	replace_program(ROOM);
}
