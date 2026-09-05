// buxue.c 布靴


#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("黑布鞋", ({ "hei buxie", "buxie", "xie", "shoes" }) );
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
