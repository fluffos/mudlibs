//baoyuan.c 宝源钱庄


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"宝源钱庄"NOR);
        set("long",
CYN"这是京城里最大的一家钱庄，它发行的银票信誉非常好，通行全国。墙上贴
着一张布告(notice)。钱庄掌柜和伙计忙忙碌碌地工作着。\n"NOR
        );

        set("item_desc", ([
			   "notice" : "
钱庄业务：查账(check)，存款(deposit)，取款(withdraw)，兑换(convert)。
\n",
        ]));
        set("objects", ([
	       __DIR__"npc/bankhuoji" : 1,
//	       __DIR__"npc/qianlaob" : 1,
        ]));

        set("no_drop",1);
        set("exits", ([
               "west" : __DIR__"fuchengdajie_n",
        ]));

        set("day_shop", 1);
        set("cost", 0);
        setup();
}


