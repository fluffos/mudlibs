// changqiang.c 长枪

#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("长枪", ({ "changqiang" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "这是一根白缨长钢枪，长可丈二，枪头隐隐透出寒光。\n");
                set("value", 1500);
                set("material", "steel");
                set("wield_msg", "$N抽出一杆根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n反别身后。\n");
        }
        init_spear(30);
        setup();
}

