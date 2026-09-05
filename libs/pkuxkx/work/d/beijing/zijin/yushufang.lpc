// Room: /d/beijing/zijin/yushufang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"御书房"NOR);
	set("long",
HIC"供皇帝大典前静心之处,屋内被值日太监搽抹得一尘不染，光可
鉴人。窗前，横陈着一张檀木紫桌，桌上齐齐地堆有一叠书，书旁一
杯“碧螺春”香气撩人。桌子东边，一炉“春晓迟”不断向外吐出涩
涩的幽香。使人一进屋便思躺倒。桌子西面，矗立着一排书架，书架
上堆满了书。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"south" : __DIR__"jingyanggong",
]));

	setup();
	replace_program(ROOM);
}
