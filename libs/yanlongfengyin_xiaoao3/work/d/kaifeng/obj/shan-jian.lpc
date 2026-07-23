// 尚方宝剑 unix 1998.10

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("尚方宝剑", ({"shan jian", "jian", "sword"}));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
	set("long", HIW"这是当今万岁赐给包龙星包大人的"NOR+HIY"尚方宝剑"NOR+HIB"可上斩皇亲, 下斩乱臣。\n"NOR);
		set("value", 80000);
		set("material", "gold");
	set("wield_msg", HIY"一阵金光闪过, $N从怀中拔出一把蓝汪汪的\n"NOR+
HIB"		*尚方宝剑*\n"NOR);
	set("unwield_msg", HIY"$N小心将尚方宝剑插回剑鞘之中\n"NOR);
}
	init_sword(1100);
	setup();
}
