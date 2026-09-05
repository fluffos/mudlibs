
// Room: /d/beijing/fuchengdajie_n.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"阜成门大街"NOR);
	set("long",
CYN"这是繁华热闹的阜成门外大街，大街街面宽阔，车水马龙，川流不息，人群
熙熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一
斑。街东便是京城里最大的钱庄—宝源钱庄。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"fuchengdajie",
	  "north" : __DIR__"xizhidajie",
	  "east"  : __DIR__"baoyuan",
	  "west"  : __DIR__"dangpu",
	]));
	set("outdoors", "beijing");

	setup();
}


