// /d/tianshui/yinhao.c

inherit BANK;
void create()
{
        set("short", "天水钱庄");
        set("long", @LONG
这是一间素来以公平信用著称的钱庄，钱庄的老板还是个曾
经中过举人的读书人，你可以看到钱庄里里外外都打扫得乾乾净
净，一个胖胖的中年人坐在柜台後面，柜台上挂著一块黑漆金字
牌子(paizi)。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"eroad1",
]));

        set("item_desc", ([
                "paizi": @TEXT
这里是钱庄，目前我们提供的服务有：
convert         兑换钱币。
cunqian         存钱
quqian          取钱
chazhang        查帐     
TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/banker": 1 ]) );
        setup();
}