// D:\xkx\d\liuxiu-shanzhuang\yaopu.c药铺
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", "药铺");
    set("long", @LONG
这是当地唯一的一家药铺，正如斑驳生锈的药柜，已显得有些颓败。
但是在捋着胡子翻账的名医“阎王敌”薛慕华却并不以为意，头也不
抬自得地在数钱。一名伙计站在柜台后招呼着顾客，柜台上摆着一
个牌子(paizi)。
LONG);

    set("indoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "paizi":"交易说明：\n	查看可卖物品："+HBBLU"list\n"NOR+"	买东西："+HBBLU"buy 物品英文id\n"NOR,
        ]));

    set("exits", ([
        "southwest" : __DIR__"jizhen-xiaodao1",
        ])
     );

	set("objects", ([
		__DIR__"npc/huoji" : 1,
		__DIR__"npc/xuemuhua" : 1,
	]));

    setup();
}

void init()
{
	add_action("show_quest","quest");
}




