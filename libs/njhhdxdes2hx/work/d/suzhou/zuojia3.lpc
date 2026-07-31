//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"左家后院"NOR);
	set("long", @LONG
你走进后院，迎面是一口大锅，一个家丁正在生火，一个家丁，正在弄鱼，左老头子正
挽着袖子准备做糖醋鱼。还没开始，你就闻到一阵阵香气。好香好诱人啊。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"zuojia2",
	]));                                      
	set("objects", ([
		__DIR__"npc/jiading" : 2,
		__DIR__"npc/zuoqh" : 1,
]));
	setup();
	replace_program(ROOM);
}
