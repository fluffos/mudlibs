// Room: /d/beijing/east/chongwendajie.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"崇文门外大街"NOR);
	set("long",
CYN"这是繁华热闹的崇文门外大街，大街街面宽阔，车水马龙
，川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百
货小吃，应有尽有，帝都风貌可见一斑。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"guangqudajie",
	"north" : __DIR__"chongwendajie",
//	"east" : __DIR__"wushengbiaoju",
	"west" : __DIR__"tiantan/dongtianmen",
]));

	setup();
	replace_program(ROOM);
}
