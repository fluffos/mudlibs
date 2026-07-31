
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("垓下刀", ({ "wangblade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把轻如雪片，快如闪电的宝刀");
                set("value", 9000);
		set("rigidity", 200);
                set("material", "steel");
        }
        init_blade(190);

        set("wield_msg", "$N从乌皮刀鞘中抽出一把杀气逼人的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回乌皮刀鞘中。\n");


        setup();
}

