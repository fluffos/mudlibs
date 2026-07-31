// bank  钱庄

#include <ansi.h>

inherit BANK;

void create()
{
        set("short", "日升隆钱庄盛京分店");
        set("long", @LONG
这是长安日升隆钱庄的盛京分号，一进门，就看到墙上有大
招牌(sign)，柜台后的小伙计满脸堆笑的迎了过来。从这里出门
就是盛京的威远路。
LONG
);
        set("item_desc", ([ /* sizeof() == 2 */
        "sign" :  "日升隆钱庄目前提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan           转账
",
]));
        set("no_beg", 1);

        set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));

	set("exits", ([
                "north" : __DIR__"wy3",
]) );
        setup();
}
