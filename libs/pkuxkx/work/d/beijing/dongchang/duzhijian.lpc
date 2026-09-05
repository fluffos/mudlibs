#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"都知监"NOR);
	set("long",
HIC"这里显得门庭冷落，只有一个小太监在打扫地面，灯光昏暗下更显得毫无生气。\n"NOR
	);

	set("exits", ([
		"southwest" : __DIR__"datang",
		"north" : __DIR__"shangyijian",
//		"east" : __DIR__"citang",
	]));
  set("objects", ([
//               __DIR__"npc/xiaotaijian" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
