// Room: /d/beijing/zijin/kunninggong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"坤宁宫"NOR);
	set("long",
HIC"    这里是皇后住的正宫，宫内花斑石墁地，方石板
上都有紫色花纹，光彩夺目，如满堂宝石，熠熠生辉。更
妙的是每当黄昏时，晃动门窗，光线若明若暗，像无数条
春蚕和紫色绒球，在黄色地板上滚动。出坤宁门就是御花
园了。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"kunningmen",
  	"south" : __DIR__"jiaotaidian",
]));

	setup();
	replace_program(ROOM);
}
