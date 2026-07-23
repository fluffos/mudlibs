// tiechan.c

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("铁铲", ({ "tiechan" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把黑黝黝的铁铲。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n背到背后。\n");
        }
        init_staff(25);
        setup();
}
