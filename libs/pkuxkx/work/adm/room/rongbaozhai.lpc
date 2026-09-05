
#include <ansi.h>

inherit F_HOCKSHOP;

void create()
{
    set("short", HIC"荣宝斋"NOR);
    set("long",
CYN"这里是京城里最有名的珠宝店。店主人刘老板见多识广，收藏的宝物也颇不
少，除了当世的名家珍品，还时常有些宝石兵器之类的，墙上挂着一块牌子（sign）。\n"NOR
	);

    set("exits", ([
        "north" : "/d/beijing/changanjie_e2",
    ]));

    set("objects", ([
	"/d/beijing/npc/liulaoban":1,
    ]));
    set("item_desc", ([
                "sign" : "公平交易，童叟无欺\n
sell        卖
buy         买
pawn        当
redeem      赎
value       估价
list        列表\n
",
    ]));
    set("no_beg",1);
    set("no_steal", 1);
    set("no_fight", 1);
    set("no_perform", 1);
    setup();
}

