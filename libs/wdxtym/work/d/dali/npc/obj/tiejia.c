// tiejia.c Ìú¼×
//

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("Ìú¼×", ({ "tie armor" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "steel");
		set("value", 2000);
	set("armor_prop/armor", 20);
	}
	setup();
}

