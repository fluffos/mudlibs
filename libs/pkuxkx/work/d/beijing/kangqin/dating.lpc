// Room: /d/beijing/kangqin/dating.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"大厅"NOR);
	set("long",
MAG"这里是王府大厅，豪华气派。康亲王平常接待贵宾都在此处。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"tianjing",
  	"north" : __DIR__"zhongmen",
  	"west" : __DIR__"zhoulang2",
 	 "east" : __DIR__"zhoulang1",
]));

	setup();
	replace_program(ROOM);
}
