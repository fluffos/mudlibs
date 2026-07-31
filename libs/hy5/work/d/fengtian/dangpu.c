// Room: /d/fengtian/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "当铺");
	set("long", @LONG
大大的一个“当”字，实际你可以发现凡是赌场火的，旁边
的当铺一定火，这间当铺当然是为银钩睹坊开的，开张后就没关
过，你说火不火！柜台边有一块木牌(sign)。
LONG
);

set("item_desc", ([
                "sign": @TEXT
当铺交易的方法:
[ value | gujia ]     : 估价
[ pawn | dang ]       : 典当
sell                  : 卖
[ redeem | shu ]      : 赎回
list                  : 列表
[ buy | mai ]         : 买
TEXT
]) );

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll1",
]));

	set("objects",([
	__DIR__"npc/dang_boss" : 1,
]));

	setup();
}
