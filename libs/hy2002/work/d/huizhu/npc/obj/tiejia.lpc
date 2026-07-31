//Mr.music yangzhou 铁甲

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("铁甲", ({ "tiejia","jia" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
                set("value", 1000);
                set("material", "steel");
		set("armor_prop/armor", 15);
	}
	setup();
}
