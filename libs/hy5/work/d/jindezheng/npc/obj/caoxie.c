#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("草鞋", ({"caoxie","boots"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "双");
                set("value",100);
                set("long","用蒲草密密编制而成的草鞋.\n");
		set("armor_prop/armor", 11);
        }
        setup();
}

