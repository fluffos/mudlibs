// Room: /d/beijing/zijin/yinghuadian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"英华殿"NOR);
	set("long",
HIC"英华殿其实就是皇太后的佛堂，皇太后经常在这里虔诚礼佛。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"shouangong",
  	"north" : __DIR__"tongdao8",
]));

	setup();
	replace_program(ROOM);
}
