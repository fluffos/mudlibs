// Room: /d/beijing/zijin/yangxingmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"养性门"NOR);
	set("long",
HIC"这是道通向养性殿的宫门。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"yangxingdian",
  	"southwest" : __DIR__"gzxd5",
]));

	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
