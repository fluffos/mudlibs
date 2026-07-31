// bank.c
// by dicky

#include <ansi.h>
inherit BANK;

void create()
{
	set("short", "龙门钱庄");
        set("long", @LONG
这里一家很小的钱庄，由于地处最偏僻的天山一带，所以生
意不是很好。据说这里的老板曾经也是一位江湖人，不知什么原
因后来定居在这里，开下这侯集阵唯一的钱庄。一进门，就看到
墙上有大招牌(sign)，钱庄老板低头理着自己的帐目，并不抬头
观看进来的是何许人，好象他已经早已知晓。
LONG
        );

        set("item_desc", ([ /* sizeof() == 2 */
	"sign" :  "龙门钱庄目前提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan		转账
",
]));
        set("no_beg", 1);

        set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));
	set("exits", ([
                "south"            : __DIR__"shilu2", ]) );
        setup();
}

