#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"御马监"NOR);
	set("long",
HIC"御马监与其他十一监有所不同的是守卫较为森严，因为掌管御用兵符，
御马监是仅次于司礼监的重要部门。门口站立了几名锦衣卫。\n"NOR
	);

	set("exits", ([
		"southwest" : __DIR__"yuyongjian",
		"north" : __DIR__"silijian",
		"southeast" : __DIR__"shengongjian",
	]));
	
  set("objects", ([
               __DIR__"npc/gudayong" : 1,
               __DIR__"npc/wangzhi" : 1,
//               __DIR__"npc/fengbao" : 1,
               __DIR__"npc/jinyiwei" : 4,
        ]));
	setup();
	replace_program(ROOM);
}
