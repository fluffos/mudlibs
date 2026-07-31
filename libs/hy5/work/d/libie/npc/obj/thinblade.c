 // Tie@fengyun
#include <weapon.h> 
inherit BLADE; 
void create()
{
    set_name("纸刀", ({ "paper dagger","dagger" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把薄如纸，轻如绢的短刀。\n");
        set("value", 5000);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
    init_blade(60);
}
