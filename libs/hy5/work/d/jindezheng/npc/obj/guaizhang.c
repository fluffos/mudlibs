
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("龙头拐杖", ({"guai zhang", "zhang", "staff"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 300);
                set("material", "wood");
                set("long", "用乌木制作的拐杖,一端成龙首形．\n");
                set("wield_msg", "$N提起一把$n握在手中。\n");
                set("unequip_msg", "$N放下手中的$n．\n");
        }
        init_staff(120);
        setup();
}

