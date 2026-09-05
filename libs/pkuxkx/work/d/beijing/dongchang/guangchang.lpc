#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"广场"NOR);
	set("long",
HIC"大门内是一片开阔地，当中竖立一个牌坊，上书：

	流     芳     百     世
							
四个大字。广场东边有一个祠堂，好象是祭祀什么人的。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"gate",
		"north" : __DIR__"datang",
		"east" : __DIR__"citang",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
