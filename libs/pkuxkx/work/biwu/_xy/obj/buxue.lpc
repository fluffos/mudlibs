// buxue.c 布靴


#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("布靴", ({ "bu xue", "buxue", "xue", "shoes" }) );
        set_weight(120);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("material", "boots");
				set("unit", "双");
				set("value", 0);
				set("armor_prop/dodge", 1);
			}
        setup();
}
