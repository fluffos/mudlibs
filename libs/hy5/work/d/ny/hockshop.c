
// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("coor",({-10,4700,10}));
	set("short", "丰登当铺");
	set("long",
"这是一家中等规模的当铺，老旧的柜台上放著一张木牌(sign)，屋里的光线不是很亮，往东\n"
"的出口被一块蓝色布□遮著，上面有「非请莫入」的字样，西边有一扇木雕门(door)通往大\n"
"街。\n"
);
    set("rich",40000);
	set("item_desc", ([
		"sign": @TEXT
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客倌可以在这里典当(pawn)、卖断(sell)各种货物，铜钱、银两、黄金、银票
一概通用。
TEXT
	]) );
	set("exits", ([
        "west" : __DIR__"hockshop2",
        "east" : __DIR__"sroad1",
	]));
        set("objects", ([
                __DIR__"npc/hocker" : 1,
                 ]) );
	setup();

}
