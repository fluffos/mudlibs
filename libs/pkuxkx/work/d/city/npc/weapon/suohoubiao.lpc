//锁喉镖

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIY"锁喉镖"NOR, ({ "suohou biao", "suohou" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "只");
                set("long", MAG"这是一只玄铁打造的暗器，锋利无比。掂在手里，沉甸甸的。\n"NOR);
                set("value", 250000);
                set("material", "steel");
                set("base_weight", 20);
                set("wield_msg", "$N从怀里拿出一只$n，握在手中。\n");
                set("unwield_msg", "$N将手中的$n拿出揣入怀中。\n");
        }
        set_amount(1);
        init_throwing(100);
        setup();
}

