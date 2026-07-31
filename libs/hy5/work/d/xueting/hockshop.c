// Room: /d/changan/hockshop.c 当铺

inherit ROOM;

void create()
{
        set("short", "张记当铺");
        set("long", @LONG
这里是雪亭镇一家不大的当铺，一进门，你便看见了高高的
柜台，柜台后一个一脸忠厚的店老板，正在忙着当着别人的东西。
他不停的叫着：收到破烂某某一件，值多少。旁边的帐房跟着在
记着帐，看来这里的生意还算是兴隆。门口有一个油黑发亮的牌
子(sign)，看得出来年代已经很古老了。
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
        set("exits", ([
                "west" : __DIR__"street02",
        ]));

	set("objects",([
		__DIR__"npc/zhangboss"	: 1,
      ]));
        setup();
}