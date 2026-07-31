// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "兴隆当铺");
	set("long", @LONG
这是一家中等规模的当铺，老旧的柜台上放著一张木牌(sign)，屋
里的光线不是很亮，西边有一扇木雕门通往大街。
LONG
	);
	set("item_desc", ([
		"sign": @TEXT
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客倌可以在这里典当(pawn)、卖断(sell)各种货物，铜钱、银两、黄金一概通用。
要赎回(retrieve)典物，请保持当票完整。
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
//	set("objects", ([
//
//	]) );

	setup();
}
