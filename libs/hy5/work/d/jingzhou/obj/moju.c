// flower.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(HIB"墨菊"NOR, ({ "mo ju","flower"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵娇艳的墨菊。\n");
		set("material", "花瓣");
		set("unit", "朵");
		set("unique", 1);
		set("value", 1000);
		set("wear_msg", "$N拈起一朵墨菊，戴在头上。$N看起来更增娇艳。\n");
		set("unequip_msg", "$N将墨菊从头上摘了下来。\n");
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	 setup();
}

