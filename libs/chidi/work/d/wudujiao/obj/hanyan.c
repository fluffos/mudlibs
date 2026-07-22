// hanyan.c 旱烟袋     
// star 1998/12/04 亮晶晶版权所有，请勿随意修改传播

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("旱烟袋", ({ "han yan", "yan" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "这是一只用了好多年的铜烟袋。\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一只$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰带中。\n");
	}
	init_sword(5);
	setup();
}
