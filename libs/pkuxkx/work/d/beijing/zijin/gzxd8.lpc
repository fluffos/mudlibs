// Room: /d/beijing/zijin/gzxd8.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"宫中小道"NOR);
	set("long",
HIC"这是宫殿之间的夹道，静静的，偶尔有几个侍卫或太监走过。小
鸟停在树枝，叽叽喳喳叫个不停。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"north" : __DIR__"gzxd9",
  	"west" : __DIR__"jingrengong",
  	"east" : __DIR__"yanxigong",
]));

	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
