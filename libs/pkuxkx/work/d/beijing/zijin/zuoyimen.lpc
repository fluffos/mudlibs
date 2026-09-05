// Room: /d/beijing/zijin/zuoyimen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"左翼门"NOR);
	set("long",
HIC"这是太和殿前广场的一个侧门，通向文华殿。从这里向南是昭德
门，东面有一条小道。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"guang1",
  	"east" : __DIR__"gzxd3",
  	"south" : __DIR__"zhaodemen",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
