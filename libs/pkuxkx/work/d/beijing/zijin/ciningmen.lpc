// Room: /d/beijing/zijin/ciningmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"慈宁门"NOR);
	set("long",
HIC"这是一扇朱漆大门，门口站着几个侍卫和太监。再往北走就是皇
太后的寝宫。任何人未得宣召，不得入内。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"cininggong",
  	"south" : __DIR__"cininghuayuan",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
