#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"东厂大堂"NOR);
	set("long",
HIC"此处为东厂的大堂，与其他地方相比，此处显得异常安静，
让人有种莫名的不安，西北出口和东北出口各通往直殿监和都
知监，中央北边则通往后院。\n"NOR
	);

	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"guangchang",
		"northwest" : __DIR__"zhidianjian",
		"northeast" : __DIR__"duzhijian",
	]));

  set("objects", ([
               __DIR__"npc/mayongcheng" : 1,
        ]));
        
	setup();
	replace_program(ROOM);
}
