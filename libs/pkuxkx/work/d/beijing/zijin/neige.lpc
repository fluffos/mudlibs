// Room: /d/beijing/zijin/neige.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"内阁"NOR);
	set("long",
HIC"内阁大学士，学士们在此办事。房间里面的桌子上铺满了笔，墨，
纸，砚。阳光从外面射进来，照在墨汁上，令空气中充满了墨香和书香。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"east" : __DIR__"wenhuadian",
]));

	setup();
	replace_program(ROOM);
}
