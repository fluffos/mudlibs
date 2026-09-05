#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"主敬殿"NOR);
	set("long",
HIC"墙脚是一桶铁沙子，另一侧竖着一个铁柱子，不知是干
什麽用的。靠里面有一把椅子，椅子旁边的桌子上放着几只
细瓷茶杯和一把紫砂的茶壶。\n"NOR
	);

	set("exits", ([
		"north" : __DIR__"wenyuange",
		"south" : __DIR__"wenhuadian",
	]));

	setup();
	replace_program(ROOM);
}