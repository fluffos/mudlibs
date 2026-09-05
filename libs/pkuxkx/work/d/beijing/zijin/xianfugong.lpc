// Room: /d/beijing/zijin/xianfugong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"咸福宫"NOR);
	set("long",
HIC"原名寿安宫，明万历时，惠王、桂王共居之。嘉庆四年，
皇帝亦常居此。同治皇帝出生在此宫。晚清时堆放什物。后面
是同道堂。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"tongdaotang",
  	"east" : __DIR__"chuxiugong",
]));

	setup();
	replace_program(ROOM);
}
