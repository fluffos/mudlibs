//铜钱镖

#include <weapon.h>
#include <ansi.h>
inherit THROWING;
//inherit BLADE;

void create()
{
        set_name(YEL"铜钱镖"NOR, ({ "tongqian biao", "biao", "tongqian" }));
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
//                 set("base_unit", "枚");
                 set("unit", "枚");
                set("long", HIG"这是一枚用铜钱打造的兵器。\n"NOR);
                set("value", 2);
                set("material", "steel");
                set("wield_msg", "$N从怀里拿出一枚铜钱镖，捏在手中。\n");
                set("unwield_msg", "$N将手中的$n揣入怀中。\n");
        }
//set_amount(1);
        init_throwing(2);
//        init_blade(2);
        setup();
}

