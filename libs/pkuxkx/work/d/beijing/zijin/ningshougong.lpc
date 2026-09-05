// Room: /d/beijing/zijin/ningshougong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"宁寿宫"NOR);
	set("long",
HIC"这座宫殿是仿坤宁宫形式建造的，只见墙壁上、桌椅上，
都是刀剑皮鞭之类的兵器，便如是个武人的居室，哪里像是
金枝玉叶的公主寝宫。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"south" : __DIR__"huangjidian",
]));

	setup();
	replace_program(ROOM);
}
