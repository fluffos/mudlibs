// SN:ERH8nE:fJ13o:9m>
// ITEM Made by player(馒头兄:bun) /data/item/b/bun-biglong.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 31 12:40:43 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m高级[33m蒸笼[2;37;0m", ({ "biglong" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;36m离[1;31m火[1;36m玄[1;37m冰[1;36m玉[2;37;0m炼制而成的一双铁掌。
[33m这真是太神奇了，比七大暗器之首的板凳还要强的武器就在你面前
看到此物，就如看到食品之神馒头兄一样如此的高傲潇洒。[2;37;0m
铁掌缘上刻着一行小字：馒头兄(bun)
");
	set("value", 1900000);
	set("point", 167);
	set("material", "stone");
	set("wear_msg", "[32m$N往[1;36m天空[2;37;0m一看，发出了非常销魂的笑声，就在此刻，[33m阵阵竹香飘了过来[2;37;0m，\n就在此时，$N的手上多了一个$n。让众人羡慕无比。[2;37;0m\n");
	set("remove_msg", "又是一阵销魂的笑声，$N把$n往空中一抛，$n已消失在众人的眼中。\n真的是比[1;31m七大暗器之首[1;36m板凳[2;37;0m还要隐密，更要神奇阿！杰克。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
