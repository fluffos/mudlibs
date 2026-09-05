#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"刑房"NOR);
	set("long",
HIC"这里是东厂的刑房。起初，东厂只负责侦缉、抓人，并没有审讯犯人
的权利，抓住的嫌疑犯要交给锦衣卫北镇抚司审理。但到了明末，东厂也
有了自己的监狱。墙壁挂满了各种行刑用具，令人望而生畏。地上躺着一
个遍体鳞伤的犯人。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"houyuan",
	]));

  set("objects", ([
               __DIR__"npc/jinyiwei" : 2,
//               __DIR__"npc/liubiao" : 1,
//               __DIR__"npc/wenquan" : 1,
        ]));
        
	setup();
	replace_program(ROOM);
}
