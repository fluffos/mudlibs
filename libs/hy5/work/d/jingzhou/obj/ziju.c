// ziju.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	string *surname=({"玛瑙盘","紫玉莲","双飞燕","碧江霞"});
	set_name(MAG+surname[random(sizeof(surname))]+NOR, ({"zi ju","flower" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵娇艳的紫菊。\n");
		set("material", "花瓣");
		set("unit", "朵");
		set("unique", 1);
		set("value", 1000);
		set("wear_msg", "$N拈起一朵紫菊，戴在头上。$N看起来更增娇艳。\n");
		set("unequip_msg", "$N将紫菊从头上摘了下来。\n");
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	 setup();
}

