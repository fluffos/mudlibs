#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name("鸳鸯长裙", ({ "cloth",}) );
        set_weight(1000);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "件");
				set("material", "cloth");
				set("armor_prop/armor", 1);
			}
        setup();
}
