#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("飞镖", ({ "fei biao", "dart","biao"}));
        
        if (clonep())
                set_default_object(__FILE__);
        else {
           
                set("long", "这是一只非常普遍的飞镖\n");
                set("unit", "只");
                 set("base_unit", "只");
                set("material", "steel");
                set("value",100);
                set("base_weight", 25);
                set("wield_msg", "$N拿出一些$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        set_amount(1);
        init_throwing(25); 
    setup();
}
