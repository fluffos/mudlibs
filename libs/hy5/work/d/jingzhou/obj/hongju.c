// hongju.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	string *surname=({"海云红","绣芙蓉","锦荔枝","美人红"});
	set_name(HIR+surname[random(sizeof(surname))]+NOR, ({"hong ju","flower" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵娇艳的红菊。\n");
		set("material", "花瓣");
		set("unit", "朵");
		set("unique", 1);
		set("value", 1000);
		set("wear_msg", "$N拈起一朵红菊，戴在头上。$N看起来更增娇艳。\n");
		set("unequip_msg", "$N将红菊从头上摘了下来。\n");
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	 setup();
}

