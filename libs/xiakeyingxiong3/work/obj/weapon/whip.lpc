// whip.c 鞭子

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("鞭子", ({ "whip" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条普通的鞭子。\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N「唰」的一声拔出一条$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_whip(25);
        setup();
}
