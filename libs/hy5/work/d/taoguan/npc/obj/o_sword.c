#include <weapon.h>
inherit SWORD; 
void create()
{
    set_name("红木剑", ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long", "一把用名贵的红木削成的宝剑。\n");
        set("value", 20000);
                set("material", "steel");
        }
    ::init_sword(40); 
        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");  
}    
