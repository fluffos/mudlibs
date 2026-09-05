// D:\xkx\d\liuxiu-shanzhuang\jiupu.c酒铺
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", "酒铺");
    set("long", @LONG
这家酒铺的老板是一名老汉。酒铺使用几根竹竿和一块旧布搭起来的，
竹竿上还挂着一个牌子(paizi)，如果下雨，老汉还要将仅有的一块油
布搭在顶上。若是起风了，老汉还要将那块油布撑起来挡风。若是大雨
挟着大风，那这酒铺就得暂时收摊了。还好这是个平静的集镇，狂风暴
雨几乎不曾见。所以酒客也就很安稳地在这喝酒了。
老汉坐在长凳上，一只胳膊倚在桌上，呆愣愣地望向西边的那片杏子林。
LONG);

    set("indoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "paizi":"交易说明：\n	查看可买物品："+HBBLU"list\n"NOR+"	买东西："+HBBLU"buy 物品英文id\n"NOR,
        ]));

    set("exits", ([
        "northwest" : __DIR__"jizhen-xiaodao1",
        ])
     );

	set("objects", ([
		__DIR__"npc/laohan" : 1,
	]));

    setup();
}

void init()
{
	add_action("show_quest", "quest");
}


