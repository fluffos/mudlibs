#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("订做的", ({ "order" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
                set("no_drop",1);
                set("owner","fengyun");
                set("no_get",1);
		set("material", "wood");
		set("armor_prop/armor", 10);
	}
	setup();
}
