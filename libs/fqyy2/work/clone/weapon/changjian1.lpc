// longsword.c 长剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("长剑", ({ "changjian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的精钢剑，但是剑上泛着磷磷的兰光。\n");
		set("value", 1500);
                set("rigidity", 1);
                set("material", "steel");
                set("poisoned", "man_poison");
                set("poison_number", 300);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(30);
	setup();
}

 