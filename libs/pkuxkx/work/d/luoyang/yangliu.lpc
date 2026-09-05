// Room: /d/beijing/west/yangliu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"杨柳胡同"NOR);
	set("long",
CYN"这是洛阳城里一条平常的小胡同，因为胡同口种有两棵杨柳树，
因而得名为杨柳胡同。胡同里面有座大宅子，最近似乎有不少操外地
口音的人出出进进。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"alley1",
        "west" : __DIR__"hutong2",
]));

        set("objects",  ([
                    "/d/beijing/npc/jialao6": 1,
        ]));
        setup();
	replace_program(ROOM);
}
