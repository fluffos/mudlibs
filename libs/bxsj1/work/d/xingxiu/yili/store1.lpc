// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","铁铺");
	set("long",@long
这是一间灯火通明的打铁铺，一个中年男子正坐在墙边发呆。他身后的炉
火烧得正旺，几名游牧民族汉子正和伙计商讨价钱，铺里的墙上有一个已经掉
漆的大招牌(sign)。
long );

	set("objects",([
		__DIR__"../npc/xue" : 1,
	]));
	set("exits",([
		"south" : __DIR__"yili2",
	]));
	set("item_desc",([
		"sign" : "打造各式钢杖。收费三两黄金。
		用 make <颜色> <名字>  来打造。
		例如 : make $HIR$ 扫地杖\n"
	]));
	setup();
}
