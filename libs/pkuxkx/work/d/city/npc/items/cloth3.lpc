// cloth.c
// 鱼鳞甲 zine 2 aug 2010


#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("鱼鳞甲", ({ "lin jia" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
			{
                set("unit", "件");
                set("material", "steel");
                set("armor_prop/armor", 250);
			}
        setup();
}

