//hupi .c
//by dwolf

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("雪狐皮", ({ "hu pi", "pi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "leather");
                set("armor_prop/armor", 5); 
		set("value", 10000);
        }
        setup();
}

