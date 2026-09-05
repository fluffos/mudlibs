#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"尚衣监"NOR);
	set("long",
HIC"尚衣监是掌管皇帝御用冠冕、袍服及屦舄、靴袜之的内侍所处的地方，
虽然地位不如司礼监、御马监，但毕竟是近身侍奉皇帝的贴身内侍，虽无
实权，但其他各监也不敢轻视尚衣监的人。 \n"NOR
	);

	set("exits", ([
		"south" : __DIR__"duzhijian",
		"north" : __DIR__"yinshoujian",
//		"east" : __DIR__"citang",
	]));

  set("objects", ([
               __DIR__"npc/weibin" : 1,
        ]));
        
	setup();
	replace_program(ROOM);
}
