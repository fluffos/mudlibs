// Room: /open/dt/hejiqianzhuang.c

inherit BANK;

void create()
{
	set("short", "和记钱庄");
	set("long", @LONG
和记钱庄是大同府里的铁招牌、老字号了，从这里支出的金
银成色特别的好，分量也很足。而且和记在全国各个大城市里都
有连号，这样做生意的人就不用带着笨重的金银到处跑了。柜台
上有一块牌子(sign)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huaandao1",
]));

        set("item_desc", ([ /* sizeof() == 2 */
	"sign" :  "和记钱庄目前提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan		转账
",
]));

	set("objects",([
	__DIR__"npc/he" : 1,
]));

	setup();
}
