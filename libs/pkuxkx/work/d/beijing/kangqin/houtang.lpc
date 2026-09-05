// Room: /d/beijing/kangqin/houtang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"后堂"NOR);
	set("long",
MAG"这里是康府后堂，东首的长廊通向一个小花园。北边是一个天井
西首的走廊通向一个小院。南边就是康亲王府的后花园。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"north" : __DIR__"tianjing",
  	"west" : __DIR__"zhoulang8",
  	"south" : __DIR__"garden",
  	"east" : __DIR__"zhoulang7",
]));

	setup();
	replace_program(ROOM);
}
