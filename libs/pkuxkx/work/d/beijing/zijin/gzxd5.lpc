// Room: /d/beijing/zijin/gzxd5.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"宫中小道"NOR);
	set("long",
HIC"这是宫殿之间的夹道，静静的，偶尔有几个侍卫或太监走过。
小鸟停在树枝，叽叽喳喳叫个不停。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"northeast" : __DIR__"yangxingmen",
  	"southeast" : __DIR__"ningshoumen",
  	"north" : __DIR__"huayuan",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
