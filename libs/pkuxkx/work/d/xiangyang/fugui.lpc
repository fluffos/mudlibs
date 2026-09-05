#include <ansi.h>
inherit ROOM;
inherit F_DEALER;
void create()
{   
	set("name", WHT"富贵小吃部"NOR);
	set("short", RED"富贵小吃部"NOR);
	set("long", 
      WHT"这里是一家小吃部,经营一些物美价廉的小吃,经济实惠,特别适合
  普通老百姓购买,以前这里的环境不怎么样,前几天进行了装修,显得
  整洁多了.看样子生意还是很兴隆的. 门口还有一块牌子(paizi).\n"NOR
	);

	set("item_desc", ([
		"paizi" : "本店专做各种沙锅,欢迎品尝。\n",
	]));

	set("objects", ([
		__DIR__"npc/cui" : 1,
        ]));

	set("exits", ([

                      "west" : __DIR__"xynorth1",
	]));

	setup();
	replace_program(ROOM);
}
