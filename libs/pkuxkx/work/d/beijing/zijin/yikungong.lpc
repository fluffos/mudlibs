// Room: /d/beijing/zijin/yikungong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"翊坤宫"NOR);
	set("long",
HIC"这是明清两代后妃们居住的地方。清代慈禧太后住储秀宫时,每
逢重大节日都要在这里接受妃嫔们的朝拜.\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"west" : __DIR__"changchungong",
  	"north" : __DIR__"tihedian",
  	"east" : __DIR__"tongdao2",
]));

	setup();
	replace_program(ROOM);
}
