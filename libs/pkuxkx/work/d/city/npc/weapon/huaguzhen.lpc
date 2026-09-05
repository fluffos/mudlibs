//化骨针

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(MAG"化骨针"NOR, ({ "huagu zhen", "zhen" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("base_unit", "根");
                set("long", HIG"这是一根化骨针，摸在手中可以感到寒气逼人。\n"NOR);
                set("value", 50000);
                set("material", "steel");
                set("base_weight", 10);
                set("wield_msg", "$N从怀里拿出一只$n，捻与指间。\n");
                set("unwield_msg", "$N将手中的$n拿出揣入怀中。\n");
        }
        set_amount(1);
        init_throwing(80);
        setup();
}

