#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"神宫监"NOR);
	set("long",
HIC"这里是神宫监,负责掌管太庙各庙洒扫、香灯等事。左边的木架摆放
了少许香烛之类的物品，有几个小太监在整理祭祀用的器皿，其中不断
有人催促着，看来很快要进行祭祀仪式了。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"sishejian",
		"northwest" : __DIR__"yumajian",
//		"east" : __DIR__"citang",
	]));
  set("objects", ([
               __DIR__"npc/luoxiang" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
