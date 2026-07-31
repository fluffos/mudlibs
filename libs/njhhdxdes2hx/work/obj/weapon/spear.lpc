// spear.c : an example weapon

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name("长枪", ({ "spear","qiang" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长枪，份量大约有二十来斤左右。\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_spear(30);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声,把$n横在胸前。\n");
	set("unwield_msg", "$N将手中的$n收起。\n");

// The setup() is required.

	setup();
}
