#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"东厂后院"NOR);
	set("long",
HIC"这里是东厂后院，院中间站立了几名锦衣卫，中间一个内侍服饰的人，
好像在等什么人。西面通往神机营，北面出口地方则显得有些阴暗。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"datang",
		"north" : __DIR__"xingfang",
		"west" : __DIR__"shenjiying",
	]));

  set("objects", ([
//               __DIR__"npc/gaofeng" : 1,
//               __DIR__"npc/qiuju" : 1,
               __DIR__"npc/jinyiwei" : 5,
        ]));
        
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
