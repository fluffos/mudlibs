// SN:76g;S]FCUFd5QD_C
// ITEM Made by player(段浪:smirk) /data/item/s/smirk-zhuantou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 30 19:45:43 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m砖头[2;37;0m", ({ "zhuantou" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;37m一块砖头！[2;37;0m
战衣缘上刻着一行小字：段浪(smirk)
");
	set("value", 2100000);
	set("point", 219);
	set("material", "silk");
	set("wear_msg", "[1;35m$N深深吸了一口气，伸出中指，使出六脉神剑绝技指法，一道真气慢慢得向你点了过去。[1;31m\n刹那间，你不知躲避，被真气点中，浑身颤抖，已经虚脱，感觉极不舒服。\n\n接着眼前一黑，接著什么也不知道了。。。。。。[2;37;0m\n");
	set("remove_msg", "[1;33m慢慢地你终于又有了知觉。。。。。。。。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
