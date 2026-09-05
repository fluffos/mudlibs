// Room: /d/beijing/zijin/tongdaotang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"同道堂"NOR);
	set("long",
HIC"因为东西太后两宫同尊，与她们挺像的，所以用慈禧
的印做名字。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"south" : __DIR__"xianfugong",
]));

	setup();
	replace_program(ROOM);
}
