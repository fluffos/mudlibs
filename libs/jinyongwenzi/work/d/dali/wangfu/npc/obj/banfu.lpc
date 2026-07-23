// banfu.c

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("槟铁板斧", ({ "bingtie banfu","fu","axe" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long", "这是一对由槟铁打制而成沉甸甸的斧头。\n");
                set("value", 1500);
                set("material", "steel");
                set("wield_msg", "$N「哐」的一声抽出一对$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_axe(25);
        setup();
}
