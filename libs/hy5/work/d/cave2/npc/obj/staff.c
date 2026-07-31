 // staff.c : Gun zi
#include <weapon.h> 
inherit STAFF; 
void create()
{
        set_name("熟铜棍", ({ "staff" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根沙场军兵用的熟铜棍。\n");
                set("value", 3000);
                set("material", "copper");
        }
        init_staff(50); 
// These properties are optional, if you don't set them, it will use the
// default values. 
        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");  
}    
