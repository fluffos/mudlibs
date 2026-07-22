// axe.c 斧头

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("斧头", ({ "axe", "fu tou" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把峨嵋派弟子遗失的斧头，是峨嵋派伐木用的。\n");
                set("value", 1500);
                set("rigidity",2);
                set("material", "steel");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_axe(25);
        setup();
}
