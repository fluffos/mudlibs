// huangju.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	string *surname=({"金芍药","黄鹤翎","报君知","莺羽黄"});
	set_name(HIY+surname[random(sizeof(surname))]+NOR, ({"huang ju","flower"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵娇艳的黄菊。\n");
		set("material", "花瓣");
		set("unit", "朵");
		set("unique", 1);
		set("value", 1000);
		set("wear_msg", "$N拈起一朵黄菊，戴在头上。$N看起来更增娇艳。\n");
		set("unequip_msg", "$N将月下白从头上摘了下来。\n");
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	 setup();
}

