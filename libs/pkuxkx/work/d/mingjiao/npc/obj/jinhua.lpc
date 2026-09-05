#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("金花", ({ "jin hua", "hua"}));
        set_weight(100);
       
        if (clonep())
                set_default_object(__FILE__);
        else {
           
                set("long", "这是一只花状的金色暗器\n");
                set("value", 100);
                set("unit", "些");
                set("material", "steel"); 
                set("mingjiao", 1);
                set("base_weight", 100);
                set("base_unit", "只");
                set("wield_msg", "$N拿出一些$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        set_amount(1);
        init_throwing(75); 
    setup();
}
