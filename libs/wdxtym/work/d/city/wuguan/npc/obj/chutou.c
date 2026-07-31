//chutou.c
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("锄头", ({ "chu tou", "tou", "staff" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把锄头，普通百姓的日常务农用品。\n");
                set("value", 50);
                set("material", "steel");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n抗在肩上。\n");
        }
        init_staff(4);
        setup();
}
