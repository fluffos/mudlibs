// Room: /d/beijing/zijin/qinandian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"钦安殿"NOR);
	set("long",
HIC"殿内供玄武大帝,是宫中举行道教活动的重要常所,每逢重大祭
礼活动,皇帝在此殿拈香行礼。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"out" : __DIR__"yuhuayuan",
]));

	setup();
	replace_program(ROOM);
}
