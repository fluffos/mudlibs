// white_dress.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("白绸羽衫", ({ "white dress", "dress" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 3200);
		set("long", "一件白色的丝绸女子衣衫，摸起来轻柔无比　\n");
		set("material", "cloth");
		set("armor_prop/armor", 11);
	}
	setup();
}
