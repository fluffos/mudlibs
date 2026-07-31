// cracked by vikee 2/09/2002   vikee@263.net
// shoupi.c

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("铠甲", ({"armor"}));
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "副");
		set("armor_prop/armor", 5);
        }
        setup();
}
