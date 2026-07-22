#include <armor.h>
 
inherit SHIELD;
 
void create()
{
        set_name("铁盾", ({ "shield", "dun" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "面");
                set("value", 1200);
                set("armor_prop/armor", 10);
                set("armor_prop/defense", 5);
        }
        setup();
}

