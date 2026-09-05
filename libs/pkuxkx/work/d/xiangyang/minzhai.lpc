#include <ansi.h>
inherit ROOM;
inherit F_DEALER;
void create()
{   
	set("name", HIW"贫苦民宅"NOR);
	set("short", HIW"贫苦民宅"NOR);
	set("long", 
      HIW"这里是一户贫苦人家,屋里四壁空空,土炕上坐着一个老头
  愁眉紧缩,唉声叹气,不知道有什么不顺心的事.东面还有一个门，通往里屋。\n"NOR
	);

	set("objects", ([
		__DIR__"npc/laozhang" : 1,
        ]));

	set("exits", ([

                      "west" : __DIR__"xynorth3", 
                      "east" : __DIR__"liwu",
	]));

	setup();
	replace_program(ROOM);
}
