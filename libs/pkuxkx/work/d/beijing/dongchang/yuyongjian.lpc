#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"御用监"NOR);
	set("long",
HIC"这里摆放着一些雕刻异常精美的屏风，御前所用围屏、床榻诸木器
及紫檀、象牙、乌木、螺钿诸玩器，皆由御用监负责造办。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"neiguanjian",
		"northeast" : __DIR__"yumajian",
//		"east" : __DIR__"citang",
	]));

	setup();
	replace_program(ROOM);
}
