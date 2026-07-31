// SN:Z6N9:BMAXD;Xk1?L
// ITEM Made by player(俞佩玉:peiyu) /data/item/p/peiyu-fuyun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 12 23:26:29 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m浮云游子意[2;37;0m", ({ "fuyun" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
[1;32m一双很普通的靴子，上面的针脚密密麻麻，显见得制作这双靴子花费了不少的心血。[2;37;0m
靴子缘上刻着一行小字：俞佩玉(peiyu)
");
	set("value", 2100000);
	set("point", 116);
	set("material", "silk");
	set("wear_msg", "[1;32m$N仔细的拿出一双很普通的靴子出来，怔怔的看了一会儿，然后缓缓的穿在了脚上。\n$N向着远方眺望，心里默默地念道：“娘，待此间事了，孩儿会早日回去。”[2;37;0m\n");
	set("remove_msg", "[1;32m$N慢慢脱下脚上穿的靴子，唯恐靴子受到一点意外的伤害，接着再细致的放入自己的包裹里面。\n$N想着做这双靴子的人的双鬓白发，眼眶已是通红如血！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
