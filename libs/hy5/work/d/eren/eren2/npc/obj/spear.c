#include <weapon.h>
inherit SPEAR; 
void create()
{
        set_name("梨花枪", ({ "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根喋血沙场上的将士常用的长枪。\n");
                set("value", 8000);
                set("material", "steel");
        }
        init_spear(50);
        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");
}  
