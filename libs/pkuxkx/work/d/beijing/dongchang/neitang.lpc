#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"内堂"NOR);
	set("long",
HIC"此处香烟缭绕，中间摆放一张柳木雕刻极为精致的卧榻，一个
慈眉善目身穿白色锦袍的老太监正横卧榻上，手里拿着个汉白玉鼻
烟壶。两名手执香扇的红衣侍女分站背后两旁，正不紧不慢地为榻
上的人扇凉风。距离卧榻二十步开外，四名锦衣卫站立两旁。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"silijian",
//		"north" : __DIR__"guangchang",
//		"east" : __DIR__"citang",
	]));
  set("objects", ([
               __DIR__"npc/weizhongxian" : 1,
               __DIR__"npc/jinyiwei" : 4,
        ]));
	setup();
	replace_program(ROOM);
}
