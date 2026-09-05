// Room: /d/beijing/zijin/tongshunzhai.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"同顺斋"NOR);
	set("long",
HIC"这里是永和宫南边的一间小偏殿．地方不大，但布置得十分雅致，
打扫得也相当整洁．一股沉香之气在室内若有若无的盘旋缭绕，令人
昏昏欲睡。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"south" : __DIR__"yonghegong",
]));

	setup();
	replace_program(ROOM);
}
