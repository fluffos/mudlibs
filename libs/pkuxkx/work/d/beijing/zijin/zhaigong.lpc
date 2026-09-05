// Room: /d/beijing/zijin/zhaigong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"斋宫"NOR);
	set("long",
HIC"这里是皇帝在祭天，祭地等大祀之前，来此斋戒的地方。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"chengsudian",
  	"west" : __DIR__"neizuomen",
]));

	setup();
	replace_program(ROOM);
}
