// ling.c 斧头

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("峨嵋令牌", ({ "ling" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把峨嵋派号令弟子的令牌。\n");
                set("value", 1500);
                set("rigidity",100);
                set("material", "steel");
                set("no_get", 1);
        }
        init_axe(25);
        setup();
}
