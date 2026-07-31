//Mr.music yangzhou Ìú¼×

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("Ìú¼×", ({ "tiejia","jia" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
                set("value", 1000);
                set("material", "steel");
		set("armor_prop/armor", 15);
	}
	setup();
}
