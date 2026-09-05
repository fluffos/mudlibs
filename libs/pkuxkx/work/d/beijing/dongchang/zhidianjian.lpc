#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"直殿监"NOR);
	set("long",
HIC"直殿监是十二监之一，主要是负责宫中清洁打扫工作的机构，
权力根本无法和掌管兵符的御马监等相提并论，这里连个像样的
管事地方都没有。\n"NOR
	);

	set("exits", ([
		"southeast" : __DIR__"datang",
		"north" : __DIR__"shangshanjian",
//		"east" : __DIR__"citang",
	]));
  set("objects", ([
               __DIR__"npc/qiuju" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
