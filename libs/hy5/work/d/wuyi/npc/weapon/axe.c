// zhubang.c 竹棒

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("劈山斧", ({ "pishanfu" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把劈山斧，似乎相当结实。\n");
                set("value", 2);
                set("material", "steel");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_axe(300);
        setup();
}

