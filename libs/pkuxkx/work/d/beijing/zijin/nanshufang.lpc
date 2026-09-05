// Room: /d/beijing/zijin/nanshufang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"南书房"NOR);
	set("long",
HIC"文学修养好的词臣在此值班,每天四人,准备皇帝随时咨询,同
时也观察这些人是否可以重用。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"nzsfang",
  	"east" : __DIR__"jingshifang",
]));

	setup();
	replace_program(ROOM);
}
