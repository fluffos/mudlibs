#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"尚宝监"NOR);
	set("long",
HIC"这里是掌管玉玺、敕符、将军印信的地方，虽然品级不高，但位置极为重要。
按大明律，皇帝下的圣旨要经过润色誊写成文，待审核之后，由主笔太监签发一
张用宝封批，再来尚宝监盖上玉玺，最后经司礼监掌印、秉笔太监批核才能可以
正式发出。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"shangshanjian",
		"north" : __DIR__"neiguanjian",
//		"east" : __DIR__"citang",
	]));
  set("objects", ([
               __DIR__"npc/gaofeng" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
