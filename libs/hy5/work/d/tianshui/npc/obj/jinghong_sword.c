// jinghong_sword.c

#include <ansi.h>
#include <weapon.h>


inherit SWORD;

void create()
{
	set_name( RED "惊鸿宝剑" NOR, ({ "jinghong sword" }) );
	set_weight(8000);
	set("valid_number",1);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long","这是一把华贵的宝剑，剑柄是由黄金打就，
上面嵌着各色宝石，剑背宽大，剑刃在阳
光的映照下泛着丝丝暗红色的光。\n"
);
		set("value", 5000);
		set("material", "black_iron");
		set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
		set("weapon_prop/karma", 10);
		set("weapon_prop/intelligence", 5);
		set("weapon_prop/personality", 5);
	}

	init_sword(575);
	setup();
}
