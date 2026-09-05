#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("木制琵琶", ({ "mu pipa", "pipa" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把白木制作的普通琵琶，做工非常精致。\n");
                set("value", 50000);
                set("material", "wood");
                set("music", "pipa");
                set("wield_msg", "$N拿起一把$n在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        init_staff(5,1);
        setup();
}